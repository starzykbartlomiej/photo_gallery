#include "cropped_image.h"
#include "ui_cropped_image.h"

Cropped_Image::Cropped_Image(QPixmap image, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cropped_Image)
{
    ui->setupUi(this);
    cropped_scene = new QGraphicsScene(this);
    cropped_scene->addPixmap(image);
    ui->cropped_view->setScene(cropped_scene);
    ui->cropped_view->setScene(cropped_scene);
    jpg = image.toImage();
    ui->cropped_view->setMinimumHeight(jpg.height());
    ui->cropped_view->setMinimumWidth(jpg.width());
    ui->cropped_view->setMaximumHeight(jpg.height());
    ui->cropped_view->setMaximumWidth(jpg.width());

}

void Cropped_Image::on_Cancel_clicked()
{
    this->destroy();
}

void Cropped_Image::on_Save_Image_clicked()
{
    QString imagePath = QFileDialog::getSaveFileName(

                    this,

                    tr("Save File"),

                    "",

                    tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )

                    );
        jpg.save(imagePath+".jpg");
        this->close();
}
