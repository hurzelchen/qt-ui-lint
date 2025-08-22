#include "ToolFactory.h"

#include <QTest>

class ToolFactoryTest : public QObject
{
    // NOLINTNEXTLINE
    Q_OBJECT

private slots:
    void initTestCase() {}

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    void hasTools()
    {
        QVERIFY(ToolFactory::availableTools().count() > 0);
    }

    void cleanupTestCase() {}
};

QTEST_MAIN(ToolFactoryTest) // NOLINT

#include "ToolFactoryTest.moc"
