#include <QtTest>

// add necessary includes here

#include "utils.h"

class DummTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void add()
    {
        Utils utils{};
        QCOMPARE(3, utils.add(1,2));
    }

};


QTEST_APPLESS_MAIN(DummTest)

#include "tst_dummtest.moc"
