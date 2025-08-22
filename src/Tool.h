#pragma once

#include "Finding.h"

#include <QSharedPointer>

class QDomElement;

class Tool
{
public:
    class RunResult
    {
    public:
        RunResult()
            : m_findings{} {};

        const QList<Finding> &findings() const
        {
            return m_findings;
        }
        bool hasFindings() const
        {
            return m_findings.count() > 0;
        }

    private:
        QList<Finding> m_findings;
    };

    Tool();
    virtual ~Tool() = default;

    virtual RunResult run(QSharedPointer<QDomElement> subject) = 0;
};
