#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QFileInfo imageFile,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    imageObject=new QImage();
    imageObject->load(imageFile.filePath());
    int height=ui->graphicsView->grab().height();
    int width=ui->graphicsView->grab().width();
    imageObject->scaled(width,height, Qt::KeepAspectRatio);
    qDebug()<<imageFile.path();
    qDebug()<<imageFile.fileName();
    qDebug()<<imageFile.filePath();
    image = QPixmap::fromImage(*imageObject);
    image.scaled(width,height, Qt::KeepAspectRatio);
    scene = new QGraphicsScene(this);
    QGraphicsPixmapItem* p=scene->addPixmap(image.scaled(width,height,Qt::KeepAspectRatio));
    scene->setSceneRect(image.scaled(width,height,Qt::KeepAspectRatio).rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(p, Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
}
Edit::~Edit()
{
    delete ui;
}

void Edit::on_rotate_clicked()
{
   ui->graphicsView->rotate(90);
   int height=ui->graphicsView->grab().height();
   int width=ui->graphicsView->grab().width();
   image = QPixmap::fromImage(*imageObject);
   image.scaled(width,height, Qt::KeepAspectRatio);
   scene = new QGraphicsScene(this);
   QGraphicsPixmapItem* p=scene->addPixmap(image.scaled(width,height,Qt::KeepAspectRatio));
   scene->setSceneRect(image.scaled(width,height,Qt::KeepAspectRatio).rect());
   ui->graphicsView->setScene(scene);
   ui->graphicsView->fitInView(p, Qt::KeepAspectRatio);
   ui->graphicsView->setScene(scene);
   image=ui->graphicsView->viewport()->grab();
}

void Edit::on_pushButton_2_clicked()
{

       QImage image2 = imageObject->convertToFormat(QImage::Format_Indexed8);
       image2.setColorCount(256);
             for(int i = 0; i < 256; i++)
             {
                 image2.setColor(i, qRgb(i, i, i));
             }
       QPixmap pixmap1(QPixmap::fromImage (image2));
       int height=ui->graphicsView->height();
       int width=ui->graphicsView->width();
       image = QPixmap::fromImage(image2);
       image.scaled(width,height, Qt::KeepAspectRatio);
       scene = new QGraphicsScene(this);
       QGraphicsPixmapItem* p=scene->addPixmap(image.scaled(width,height,Qt::KeepAspectRatio));
       scene->setSceneRect(image.scaled(width,height,Qt::KeepAspectRatio).rect());
       ui->graphicsView->setScene(scene);
       ui->graphicsView->fitInView(p, Qt::KeepAspectRatio);
       ui->graphicsView->setScene(scene);
       image=ui->graphicsView->viewport()->grab();

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
