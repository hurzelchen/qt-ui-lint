#include "ToolFactory.h"

#include "Tool.h"

#include <utility>

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
ToolFactory *ToolFactory::s_singleton = nullptr;

// = QMap<QString, std::function<QSharedPointer<Tool>()>>();

QStringList ToolFactory::availableTools()
{
    return instance().m_availableTools.keys();
}

QList<QSharedPointer<Tool>> ToolFactory::getTools(const QStringList &toolNameList)
{
    QList<QSharedPointer<Tool>> result;

    for (const QString &toolName : toolNameList)
    {
        if (instance().m_availableTools.contains(toolName))
        {
            result.append(instance().m_availableTools[toolName]());
        }
    }

    return result;
}

void ToolFactory::registerToolConstructor(const QString &toolName,
                                          std::function<QSharedPointer<Tool>()> constructor)
{
    instance().m_availableTools[toolName] = std::move(constructor);
}

ToolFactory::~ToolFactory() = default;

ToolFactory::ToolFactory() = default;

ToolFactory &ToolFactory::instance()
{
    if (!s_singleton)
    {
        s_singleton = new ToolFactory();
    }

    return *s_singleton;
}
