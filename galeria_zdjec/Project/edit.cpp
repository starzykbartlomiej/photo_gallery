#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QFileInfo imageFile,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
   ui->setupUi(this);
   imageObject=new QImage();
   imageObject->load(imageFile.filePath());
   int height=ui->graphicsView->height();
   int width=ui->graphicsView->width();
   imageObject->scaled(width,height, Qt::KeepAspectRatio);
   qDebug()<<imageFile.path();
   qDebug()<<imageFile.fileName();
   qDebug()<<imageFile.filePath();
   image = QPixmap::fromImage(*imageObject);
   image.scaled(width,height, Qt::KeepAspectRatio);
   scene = new QGraphicsScene(this);
   QGraphicsPixmapItem* p=scene->addPixmap(image);
   scene->setSceneRect(image.rect());
   ui->graphicsView->setScene(scene);
   ui->graphicsView->fitInView(QRectF(0, 0, width, height), Qt::KeepAspectRatio);
}
Edit::~Edit()
{
    delete ui;
}
