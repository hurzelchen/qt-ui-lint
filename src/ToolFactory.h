#pragma once

#include <QMap>
#include <QSharedPointer>
#include <QString>

#include <functional>

class Tool;

class ToolFactory
{
public:
    static QStringList availableTools();

    static QList<QSharedPointer<Tool>> getTools(const QStringList &toolNameList);

    static void registerToolConstructor(const QString &toolName,
                                        std::function<QSharedPointer<Tool>()> constructor);

private:
    ToolFactory() = delete;
    virtual ~ToolFactory() = delete;

    static QMap<QString, std::function<QSharedPointer<Tool>()>> s_availableTools;
};
