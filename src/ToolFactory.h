#pragma once

#include <QMap>
#include <QSharedPointer>
#include <QString>

#include <functional>

class Tool;

class ToolFactory
{
public:
    ToolFactory(const ToolFactory &) = delete;
    ToolFactory &operator=(const ToolFactory &) = delete;

    static QStringList availableTools();

    static QList<QSharedPointer<Tool>> getTools(const QStringList &toolNameList);

    static void registerToolConstructor(const QString &toolName,
                                        std::function<QSharedPointer<Tool>()> constructor);

    virtual ~ToolFactory();

private:
    ToolFactory();

    static ToolFactory &instance();
    static ToolFactory *s_singleton;

    QMap<QString, std::function<QSharedPointer<Tool>()>> m_availableTools;
};
