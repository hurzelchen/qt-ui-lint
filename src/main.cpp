#include <QTextStream>

int main(int argc, char** argv)
{
    QTextStream cout(stdout);
    cout << "Hello Qt UI lint!" << Qt::endl;
    return 0;
}
