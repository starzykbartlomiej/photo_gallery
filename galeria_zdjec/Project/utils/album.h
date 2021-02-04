#ifndef ALBUM_H
#define ALBUM_H
#include <QDirIterator>
#include <QDir>
#include <QDebug>
#include <QObject>

class Album
{
public:
    Album();
    std::vector<QDir> GetAlbum();
    void addToAlbum(QString albumName);
    void removeAlbum(QString albumName);
private:
    std::vector<QString> dirPath;
    std::vector<QDir> AlbumList;
};

#endif // ALBUM_H
