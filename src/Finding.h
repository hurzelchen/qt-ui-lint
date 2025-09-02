#pragma once

#include <QString>

class Finding
{
public:
    Finding(QString filename, QString message);
    virtual ~Finding();

    QString toString();

protected:
    virtual const QString &messageHeading() = 0;

    QString m_filename;
    QString m_message;
    int m_line;
    int m_column;
};

class Warning : public Finding
{
public:
    Warning(QString filename, QString message);
    virtual ~Warning();

    const QString &messageHeading() override;
};

class Error : public Finding
{
public:
    Error(QString filename, QString message);
    virtual ~Error();

    const QString &messageHeading() override;
};

class ParserError : public Error
{
public:
    ParserError(QString filename, QString message);
    virtual ~ParserError();

    const QString &messageHeading() override;
};
