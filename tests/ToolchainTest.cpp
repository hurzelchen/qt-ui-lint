#include "Toolchain.h"

#include <QBuffer>
#include <QTest>

class ToolchainTest : public QObject
{
    // NOLINTNEXTLINE
    Q_OBJECT

private slots:
    void initTestCase() {}

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    void noToolsDoNothing()
    {
        QByteArray originalTestSubject;
        QByteArray testSubject(originalTestSubject);

        auto testSubjectPtr = QSharedPointer<QIODevice>{new QBuffer{&testSubject}};
        QList<QSharedPointer<Tool>> toolList{};

        Toolchain toolchain{testSubjectPtr, toolList};

        Toolchain::RunResult runResult = toolchain.run();

        QVERIFY(!runResult.hasFindings());
        QCOMPARE(runResult.findings().count(), 0);
    }

    void cleanupTestCase() {}
};

QTEST_MAIN(ToolchainTest) // NOLINT

#include "ToolchainTest.moc"
