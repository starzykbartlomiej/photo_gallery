#include "album.h"
#include "ui_album.h"

Album::Album(QGraphicsScene* scene,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

Album::~Album()
{
    delete ui;
}
