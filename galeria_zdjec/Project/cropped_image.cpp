#include "cropped_image.h"
#include "ui_cropped_image.h"

Cropped_Image::Cropped_Image(QPixmap image, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cropped_Image)
{
    ui->setupUi(this);
}

void Cropped_Image::on_Cancel_clicked()
{

}
