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

       image = ui->graphicsView->viewport()->grab();


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

}
