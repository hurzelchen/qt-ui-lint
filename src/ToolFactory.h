#pragma once

#include <QString>

class Tool;

class ToolFactory
{
public:
    static QStringList availableTools();

private:
    ToolFactory() = delete;
    virtual ~ToolFactory() = delete;
};
