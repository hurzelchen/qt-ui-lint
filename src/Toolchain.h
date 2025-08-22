#pragma once

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
        const QStringList &findings() const
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

        QStringList m_findings;

        friend class Toolchain;
    };

    Toolchain(const QSharedPointer<QIODevice> &subject, const QList<QSharedPointer<Tool>> &tools);
    virtual ~Toolchain() = default;

    RunResult run();

private:
    QSharedPointer<QIODevice> m_subject;
    QList<QSharedPointer<Tool>> m_tools;
};
