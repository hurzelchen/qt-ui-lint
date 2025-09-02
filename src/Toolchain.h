#pragma once

#include "Finding.h"

#include <QList>
#include <QSharedPointer>

class Tool;
class QIODevice;

class Toolchain
{
public:
    class RunResult
    {
    public:
        const QList<QSharedPointer<Finding>> &findings() const
        {
            return m_findings;
        }
        bool hasFindings() const
        {
            return m_findings.count() > 0;
        }

    private:
        RunResult()
            : m_findings{} {};

        QList<QSharedPointer<Finding>> m_findings;

        friend class Toolchain;
    };

    Toolchain(QString filename,
              const QSharedPointer<QIODevice> &subject,
              const QList<QSharedPointer<Tool>> &tools);
    virtual ~Toolchain() = default;

    RunResult run();

private:
    QString m_filename;
    QSharedPointer<QIODevice> m_subject;
    QList<QSharedPointer<Tool>> m_tools;
};
