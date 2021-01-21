#ifndef ALBUM_H
#define ALBUM_H

#include <QDialog>
#include <QGraphicsScene>

namespace Ui {
class Album;
}

class Album : public QDialog
{
    Q_OBJECT

public:
    explicit Album(QGraphicsScene* scene,QWidget *parent = nullptr);
    ~Album();

private:
    Ui::Album *ui;
};

#endif // ALBUM_H
