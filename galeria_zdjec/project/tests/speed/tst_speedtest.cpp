#include <QtTest>

// add necessary includes here

#include "utils.h"

class speedTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void SpeedInitial()
    {
        auto speed = Speed();
        QCOMPARE(0.0f, speed.get());
    }

    void SpeedOneDisplacement()
    {
        auto speed = Speed();
        speed.notify(1);
        QCOMPARE(0.0f, speed.get());
    }

    void SpeedTwoDisplacements()
    {
        auto speed = Speed();
        speed.notify(1);
        speed.notify(2);
        QCOMPARE(1.0f, speed.get());
    }

    void SpeedThreeIdenticalDisplacements()
    {
        auto speed = Speed();
        speed.notify(1);
        speed.notify(2);
        speed.notify(3);
        QCOMPARE(1.0f, speed.get());
    }

    void SpeedDifferenceInDisplacementsBiggerThanOne()
    {
        auto speed = Speed();
        speed.notify(1);
        speed.notify(3);
        QCOMPARE(2.0f, speed.get());
    }

    void SpeedNegativeDifferenceInDisplacements()
    {
        auto speed = Speed();
        speed.notify(3);
        speed.notify(1);
        QCOMPARE(-2.0f, speed.get());
    }

    void SpeedSameDisplacements()
    {
        auto speed = Speed();
        speed.notify(3);
        speed.notify(3);
        QCOMPARE(0.0f, speed.get());
    }

};

QTEST_APPLESS_MAIN(speedTest)

#include "tst_speedtest.moc"
