
#include <QtTest>

// add necessary includes here

class Testy : public QObject
{
    Q_OBJECT

private slots:
    void add(){
        QCOMPARE(3, 2+1);
    }

};


QTEST_APPLESS_MAIN(Testy)

#include "tst_testy.moc"
