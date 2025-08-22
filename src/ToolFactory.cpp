#include "ToolFactory.h"

#include "Tool.h"

#include <utility>

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
QMap<QString, std::function<QSharedPointer<Tool>()>> ToolFactory::s_availableTools{};

QStringList ToolFactory::availableTools()
{
    return s_availableTools.keys();
}

void ToolFactory::registerToolConstructor(const QString &toolName,
                                          std::function<QSharedPointer<Tool>()> constructor)
{
    s_availableTools[toolName] = std::move(constructor);
}
