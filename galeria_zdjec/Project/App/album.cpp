#include "album.h"
#include "ui_album.h"

Album::Album(QString path,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
    QString holder;
    auto pathList = path.split("/");
    auto last_element = pathList.last();
    pathList.removeLast();
    holder = pathList.join("/");
    holder = holder+"/"+last_element+"/description_"+last_element+".txt";
    QFile file(holder);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream instream(&file);
    QString line = instream.readLine();
    file.close();
    ui->textDescription->setText(line);
    QDirIterator it(path, {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
    while(it.hasNext()){
        it.next();
        if(it.fileInfo().isFile())
        imagesInfos.push_back(it.fileInfo());
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
