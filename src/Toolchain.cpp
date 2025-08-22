#include "Toolchain.h"

Toolchain::Toolchain(const QSharedPointer<QIODevice> &subject,
                     const QList<QSharedPointer<Tool>> &tools)
    : m_subject(subject),
      m_tools(tools)
{
}

Toolchain::RunResult Toolchain::run()
{
    if (m_tools.empty())
    {
        return {};
    }

    return {};
}
