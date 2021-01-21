#include "album.h"
#include "ui_album.h"

Album::Album(QString path,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
    QDirIterator it(path, {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
    while(it.hasNext()){
        it.next();
        if(it.fileInfo().isFile())
        imagesInfos.push_back(it.fileInfo());
        qDebug()<<it.fileName();
    }
    ui->listWidget->setViewMode(QListWidget::IconMode);
    ui->listWidget->setIconSize(QSize(80,80));
    ui->listWidget->setResizeMode(QListWidget::Adjust);
    foreach(auto imageinfo, imagesInfos)
    {
        auto item = new QListWidgetItem(QIcon(imageinfo.path() + '/' + imageinfo.fileName()),imageinfo.fileName());
        ui->listWidget->addItem(item);
        imagesItems.push_back(*item);
    }

}

Album::~Album()
{
    delete ui;
}
