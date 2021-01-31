#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QFileInfo imageFile,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    imageObject=new QImage();
    imageObject->load(imageFile.filePath());
    image = QPixmap::fromImage(*imageObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
}
Edit::~Edit()
{
    delete ui;
}

void Edit::on_rotate_clicked()
{

   ui->graphicsView->rotate(90);
   scene = new QGraphicsScene(this);
   scene->addPixmap(image);
   scene->setSceneRect(image.rect());
   ui->graphicsView->setScene(scene);
   image=ui->graphicsView->grab();

}

void Edit::on_pushButton_2_clicked()
{

       //*imageObject=ui->graphicsView->grab().toImage();
       int height=ui->graphicsView->height();
       int width=ui->graphicsView->width();
       //imageObject->scaled(width,height, Qt::KeepAspectRatio);
       *imageObject = imageObject->convertToFormat(QImage::Format_Indexed8);
       imageObject->setColorCount(256);
             for(int i = 0; i < 256; i++)
             {
                 imageObject->setColor(i, qRgb(i, i, i));
             }
       QPixmap pixmap1(QPixmap::fromImage (*imageObject));
       image = pixmap1;
       scene = new QGraphicsScene(this);
       scene->addPixmap(image);
       scene->setSceneRect(image.rect());
       ui->graphicsView->setScene(scene);

}
void Edit::on_pushButton_clicked()
{
        QString imagePath = QFileDialog::getSaveFileName(

                        this,

                        tr("Save File"),

                        "",

                        tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )

                        );



            *imageObject = image.toImage();
            imageObject->save(imagePath+".jpg");
            this->close();
            edit=1;
            f=new QFileInfo(imagePath+".jpg");


}
QFileInfo* Edit::file(){
    return f;
}

