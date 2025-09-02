#include "Finding.h"

#include <utility>

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
Finding::Finding(QString filename, QString message)
    : m_filename{std::move(filename)},
      m_message{std::move(message)},
      m_line(-1),
      m_column(-1)
{
}

Finding::~Finding() = default;

QString Finding::toString()
{
    QString result = m_filename + QStringLiteral(":");

    if (m_line > 0)
    {
        result += QStringLiteral(":") + QString::number(m_line);

        if (m_column > 0)
        {
            result += QStringLiteral(":") + QString::number(m_column);
        }
    }

    result += QStringLiteral(" ") + messageHeading() + QStringLiteral(":");

    return result;
}

Warning::Warning(QString filename, QString message)
    : Finding(std::move(filename), std::move(message))
{
}

Warning::~Warning() = default;

const QString &Warning::messageHeading()
{
    static QString warning = QStringLiteral("warning");
    return warning;
}

Error::Error(QString filename, QString message)
    : Finding(std::move(filename), std::move(message))
{
}

const QString &Error::messageHeading()
{
    static QString error = QStringLiteral("error");
    return error;
}

Error::~Error() = default;

ParserError::ParserError(QString filename, QString message)
    : Error(std::move(filename), std::move(message))
{
}

ParserError::~ParserError() = default;

const QString &ParserError::messageHeading()
{
    static QString parserError = QStringLiteral("parser error");
    return parserError;
}
