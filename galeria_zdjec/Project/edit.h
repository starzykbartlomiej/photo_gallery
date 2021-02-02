#ifndef EDIT_H
#define EDIT_H
#include <QDialog>
#include <QFileInfo>
#include <QDebug>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QIcon>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QRubberBand>


namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QFileInfo image,QWidget *parent = nullptr);
    QFileInfo* file();
    int edit=0;
    ~Edit();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_rotate_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    QFileInfo *f;
    Ui::Edit *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QPoint position;
    QMouseEvent * event;
    QRubberBand * rubberBand;
};

#endif // EDIT_H
