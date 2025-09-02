#include "ToolFactory.h"

#include "Tool.h"

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

    void allToolsKnowTheirName()
    {
        QStringList toolNames = ToolFactory::availableTools();

        for (const QString &name : toolNames)
        {
            QList<QSharedPointer<Tool>> toolList = ToolFactory::getTools(toolNames);
            QCOMPARE(toolList.count(), 1);
            QCOMPARE(toolList[0]->name(), name);
        }
    }

    void cleanupTestCase() {}
};

QTEST_MAIN(ToolFactoryTest) // NOLINT

#include "ToolFactoryTest.moc"
