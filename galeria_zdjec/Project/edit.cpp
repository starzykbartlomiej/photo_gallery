#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QFileInfo imageFile,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    change = false;
    ui->setupUi(this);
    imageObject=new QImage();
    imageObject->load(imageFile.filePath());
    image = QPixmap::fromImage(*imageObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    //scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    //ui->graphicsView->setMouseTracking(true);
}
Edit::~Edit()
{
    delete ui;
}

void Edit::on_rotate_clicked()
{

    QTransform rotating;
    rotating.rotate(90);
   *imageObject= imageObject->transformed(rotating);
   image = QPixmap::fromImage(*imageObject);
   scene = new QGraphicsScene(this);
   scene->addPixmap(image);
   scene->setSceneRect(image.rect());
   ui->graphicsView->setScene(scene);

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
//void Edit::mousePressEvent(QMouseEvent *event)
//{
//    position = event->pos();
//    rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->graphicsView);
//    rubberBand->setGeometry(QRect(position
//                                  , QSize()));
//    rubberBand->show();
//}

//void Edit::mouseMoveEvent(QMouseEvent *event)
//{
//    rubberBand->setGeometry(QRect(position, event->pos()).normalized());
//}

//void Edit::mouseReleaseEvent(QMouseEvent *event)
//{
//    //rubberBand->hide();
//    // determine selection, for example using QRect::intersects()
//    // and QRect::contains().
//}


void Edit::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{
    if(change == true)
        change = false;
    else
        change = true;
    if(viewportRect.isNull())
    {
        change = !change;
        qDebug() << arr[change];
        QPixmap cropped = image.copy(arr[change]);
        scene->addPixmap(cropped);
        return;
    }
    arr[change] = viewportRect;
    QImage croped = imageObject->copy(viewportRect);
}

