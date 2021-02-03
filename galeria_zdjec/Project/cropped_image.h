#pragma once
#ifndef CROPPED_IMAGE_H
#define CROPPED_IMAGE_H

#include <QObject>
#include <QWidget>
#include <QDialog>

namespace Ui{
    class Cropped_Image;
}

class Cropped_Image : public QDialog
{
    Q_OBJECT
public:
    explicit Cropped_Image(QPixmap image, QWidget *parent);

signals:

private slots:
    void on_Cancel_clicked();

private:
    Ui::Cropped_Image *ui;

};

#endif // CROPPED_IMAGE_H
