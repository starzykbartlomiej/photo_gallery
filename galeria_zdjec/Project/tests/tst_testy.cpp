
#include <QtTest>

// add necessary includes here

class Testy : public QObject
{
    Q_OBJECT

public:
    Testy();
    ~Testy();

private slots:
    void test_case1();

};

Testy::Testy()
{

}

Testy::~Testy()
{

}

void Testy::test_case1()
{

}

QTEST_APPLESS_MAIN(Testy)

#include "tst_testy.moc"
