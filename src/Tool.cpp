#include "Tool.h"

#include <QTextStream>

void Tool::helloTool()
{
    QTextStream cout(stdout);
    cout << "Hello Qt UI lint tool!" << Qt::endl;
}
