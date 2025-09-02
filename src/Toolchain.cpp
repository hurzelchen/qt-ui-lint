#include "Toolchain.h"

#include "Tool.h"

#include <QDomDocument>
#include <QIODevice>

#include <utility>

Toolchain::Toolchain(QString filename,
                     const QSharedPointer<QIODevice> &subject,
                     const QList<QSharedPointer<Tool>> &tools)
    : m_filename(std::move(filename)),
      m_subject(subject),
      m_tools(tools)
{
}

Toolchain::RunResult Toolchain::run()
{
    if (m_tools.empty())
    {
        return {};
    }

    QDomDocument domDocument{};

    QList<QSharedPointer<Finding>> findings;
    bool hasParserError = true;

#if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)

#else
    QString errorMessage{};
    int errorLine = -1;
    int errorColumn = -1;

    hasParserError
        = !domDocument.setContent(m_subject.data(), &errorMessage, &errorLine, &errorColumn);

    if (hasParserError)
    {
        findings.append(QSharedPointer<Finding>(new ParserError(m_filename, errorMessage)));
    }
#endif

    for (QSharedPointer<Tool> &tool : m_tools)
    {
        tool->run(&domDocument);
    }

    return {};
}
