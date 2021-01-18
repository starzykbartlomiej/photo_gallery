#include <QtTest>

// add necessary includes here

#include "utils.h"

class displacementTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void DisplacementInitial()
    {
     auto displacement = Displacement();
     displacement.set(1);
     QCOMPARE(1.0f, displacement.getX());
    }

};

QTEST_APPLESS_MAIN(displacementTest)

#include "tst_displacementtest.moc"
