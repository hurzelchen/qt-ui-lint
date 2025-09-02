#pragma once

#include "Finding.h"

#include <QSharedPointer>

class QDomDocument;

class Tool
{
public:
    class RunResult
    {
    public:
        RunResult()
            : m_findings{} {};

        const QList<QSharedPointer<Finding>> &findings() const
        {
            return m_findings;
        }
        bool hasFindings() const
        {
            return m_findings.count() > 0;
        }

    private:
        QList<QSharedPointer<Finding>> m_findings;
    };

    Tool();
    virtual ~Tool() = default;

    virtual const QString &name() const = 0;

    virtual RunResult run(QDomDocument *subject) = 0;
};
