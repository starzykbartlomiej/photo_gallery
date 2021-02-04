
#include <QtTest>
#include <utils.h>

// add necessary includes here

class Testy : public QObject
{
    Q_OBJECT

private slots:
    void add(){
        QCOMPARE(3, 2+1);
    }
    void Photo(){
        QFileInfo f("c:/temp/foo");
        Image i(f);
        QCOMPARE(f.filePath(),i.getpath());
    }
    void AlbumVector(){
        Album a;
        QDirIterator itr(QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums",QDir::AllDirs| QDir::NoDotAndDotDot);
        std::vector<QDir> v;
        while (itr.hasNext()) {
                    v.push_back(itr.next());
        }
        QCOMPARE(a.GetAlbum().at(0),v.at(0));
    }
    void AddAlbum(){
        Album a;
        a.removeAlbum("KoronaKielce");
        int size=a.GetAlbum().size();
        a.addToAlbum("KoronaKielce");
        QVERIFY(a.GetAlbum().size()!=size);
    }
    void AddAlbum2(){
        Album a;
        a.addToAlbum("WislaKrakow");
        int size=a.GetAlbum().size();
        a.addToAlbum("WislaKrakow");
        //int size=a.GetAlbum().size();
        QVERIFY(a.GetAlbum().size()==size);
    }
    void RemoveAlbum(){
        Album a;
        a.addToAlbum("LegiaWarszawa");
        int size=a.GetAlbum().size();
        a.removeAlbum("LegiaWarszawa");
        QVERIFY(a.GetAlbum().size()!=size);


    }



};

QTEST_APPLESS_MAIN(Testy)

#include "tst_testy.moc"
