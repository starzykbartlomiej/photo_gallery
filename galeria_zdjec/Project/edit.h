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
#include <QGraphicsView>


namespace Ui {
class Edit;
class mouseEvents;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QFileInfo image,QWidget *parent = nullptr);
    QFileInfo* file();
    int edit=0;
    ~Edit();
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_rotate_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

private:
    QFileInfo * f;
    Ui::Edit *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QPoint position;
    QMouseEvent * event;
    QRubberBand * rubberBand;
    QRect arr[2];
    QRect * point;
    bool change;
};

#endif // EDIT_H
