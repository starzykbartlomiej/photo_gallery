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


namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QFileInfo image,QWidget *parent = nullptr);
    ~Edit();

private slots:
    void on_rotate_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::Edit *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // EDIT_H
