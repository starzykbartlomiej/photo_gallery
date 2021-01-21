#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QFileInfo imageFile,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    qDebug()<<imageFile.filePath()+'/'+imageFile.fileName();
    img=new QIcon(imageFile.filePath()+'/'+imageFile.fileName());
    int width=ui->ImgLabel->width();
    int height=ui->ImgLabel->height();
    ui->ImgLabel->setAlignment(Qt::AlignCenter);
    auto pix=img->pixmap(QSize(width, height));
    ui->ImgLabel->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));
}
Edit::~Edit()
{
    delete ui;
}
