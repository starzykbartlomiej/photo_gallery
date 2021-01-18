#include <QtTest>

// add necessary includes here

#include "utils.h"

class accelerationTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void AccelerationInitial()
    {
        auto acceleration = Acceleration();
        QCOMPARE(0.0f, acceleration.get());
    }

    void AccelerationOneDisplacement()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        QCOMPARE(0.0f, acceleration.get());
    }

    void AccelerationTwoDisplacements()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        acceleration.notify(1);
        QCOMPARE(0.0f, acceleration.get());
    }

    void AccelerationThreeIdenticalDisplacements()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        acceleration.notify(1);
        acceleration.notify(1);
        QCOMPARE(0.0f, acceleration.get());
    }

    void AccelerationSameDerivatives()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        acceleration.notify(2);
        acceleration.notify(3);
        QCOMPARE(0.0f, acceleration.get());
    }

    void AccelerationDifferentDerivatives()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        acceleration.notify(2);
        acceleration.notify(4);
        QCOMPARE(1.0f, acceleration.get());
    }

    void AccelerationDifferentDerivativesNegative()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        acceleration.notify(3);
        acceleration.notify(4);
        QCOMPARE(-1.0f, acceleration.get());
    }

    void AccelerationFourDisplacements()
    {
        auto acceleration = Acceleration();
        acceleration.notify(1);
        acceleration.notify(2);
        acceleration.notify(3);
        acceleration.notify(5);
        QCOMPARE(1.0f, acceleration.get());
    }

};


QTEST_APPLESS_MAIN(accelerationTest)

#include "tst_accelerationtest.moc"
