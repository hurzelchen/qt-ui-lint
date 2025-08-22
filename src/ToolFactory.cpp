#include "ToolFactory.h"

#include <QList>

QStringList ToolFactory::availableTools()
{
    return {QStringLiteral("Hello ToolFactory!")};
}
