#pragma once
#ifndef CROPPED_IMAGE_H
#define CROPPED_IMAGE_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QGraphicsScene>
#include "edit.h"

namespace Ui{
    class Cropped_Image;
}

class Cropped_Image : public QDialog
{
    Q_OBJECT
public:
    explicit Cropped_Image(QPixmap image, QWidget *parent);
    QFileInfo *file();
    int spr=0;
    //~Cropped_Image();

signals:

private slots:
    void on_Cancel_clicked();
    void on_Save_Image_clicked();

private:
    Ui::Cropped_Image *ui;
    QGraphicsScene * cropped_scene;
    QImage jpg;
    QFileInfo *f;
};

#endif // CROPPED_IMAGE_H
