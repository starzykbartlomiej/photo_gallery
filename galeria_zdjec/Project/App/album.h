#ifndef ALBUM_H
#define ALBUM_H

#include <QDialog>
#include <QGraphicsScene>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QListWidget>

namespace Ui {
class Album;
}

class Album : public QDialog
{
    Q_OBJECT

public:
    explicit Album(QString it,QWidget *parent = nullptr);
    ~Album();

private:
    Ui::Album *ui;
    std::vector<QFileInfo> imagesInfos;
    std::vector<QListWidgetItem> imagesItems;
};

#endif // ALBUM_H
