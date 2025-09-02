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
        QByteArray originalTestSubject = "<ui version=\"4.0\" >\n"
                                         " <author></author>\n"
                                         " <comment></comment>\n"
                                         "</ui>";
        QByteArray testSubject(originalTestSubject);

        auto testSubjectPtr = QSharedPointer<QIODevice>{new QBuffer{&testSubject}};
        QList<QSharedPointer<Tool>> toolList{};

        Toolchain toolchain{QString::fromLocal8Bit(__FUNCTION__), testSubjectPtr, toolList};

        Toolchain::RunResult runResult = toolchain.run();

        QVERIFY(!runResult.hasFindings());
        QCOMPARE(runResult.findings().count(), 0);

        QCOMPARE(originalTestSubject, testSubject);
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    void noOpOnlyChangesWhitespace()
    {
        QByteArray originalTestSubject = "<ui version=\"4.0\" >\n"
                                         " <author></author>\n"
                                         " <comment></comment>\n"
                                         "</ui>";
        QByteArray testSubject(originalTestSubject);

        auto testSubjectPtr = QSharedPointer<QIODevice>{new QBuffer{&testSubject}};
        QList<QSharedPointer<Tool>> toolList{};

        Toolchain toolchain{QString::fromLocal8Bit(__FUNCTION__), testSubjectPtr, toolList};

        Toolchain::RunResult runResult = toolchain.run();

        QVERIFY(!runResult.hasFindings());
        QCOMPARE(runResult.findings().count(), 0);

        QCOMPARE(originalTestSubject, testSubject);
    }

    void cleanupTestCase() {}
};

QTEST_MAIN(ToolchainTest) // NOLINT

#include "ToolchainTest.moc"
