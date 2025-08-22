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
        const QList<Finding> &findings() const
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

        QList<Finding> m_findings;

        friend class Toolchain;
    };

    Tool();
    virtual ~Tool() = default;

    virtual RunResult run(QSharedPointer<QDomElement> subject) = 0;
};
