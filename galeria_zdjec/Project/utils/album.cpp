#include "album.h"

Album::Album()
{
    QDir dir(QDir::home());
    QDir::setCurrent(dir.path());
    //QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
    QDirIterator itr(dir.path()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums",QDir::AllDirs| QDir::NoDotAndDotDot);
    while (itr.hasNext()) {
                AlbumList.push_back(itr.next());
    }

}
std::vector<QDir> Album::GetAlbum(){
    return AlbumList;
}
void Album::addToAlbum(QString albumName){
    QDir dir(QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums");
    dir.setCurrent("/oop_2020_galeria_zdjec/galeria_zdjec/Albums");
    if(dir.exists(albumName))
    {
      qDebug()<<"This album exist";

    }else{
    QDir dir2(albumName);
    dir.mkdir(dir2.dirName());
    AlbumList.push_back(dir2);
    }

}
void Album::removeAlbum(QString albumName){
    QDir dir(QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums");
    dir.setCurrent(QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums");
    if(dir.exists(albumName))
    {
      QDir dir_remove(albumName);
      dir_remove.removeRecursively();

    }
    AlbumList.clear();
    //QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
    QDirIterator itr(dir.path()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums",QDir::AllDirs| QDir::NoDotAndDotDot);
    while (itr.hasNext()) {
                AlbumList.push_back(itr.next());
    }
}
