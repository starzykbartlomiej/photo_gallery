#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // picture viewing

    QPixmap pix("/home/student/oop_2020_galeria_zdjec/galeria_zdjec/Project/img/grandma.jpg");
    int width = ui->label_picture->width();
    int height = ui->label_picture->height();
    ui->label_picture->setAlignment(Qt::AlignCenter);
    ui->label_picture->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));


    //thumbnails
    QDir dir(QDir::home());
    QDir::setCurrent(dir.path());
    QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
//    QStringList images;
    std::vector<QFileInfo> images;
    while(it.hasNext())
    {
        it.next();
        if(it.fileInfo().isFile())
            images.push_back(it.fileInfo());
    }
    ui->listWidget->setViewMode(QListWidget::IconMode);
    ui->listWidget->setIconSize(QSize(130,130));
    ui->listWidget->setResizeMode(QListWidget::Adjust);
    foreach(auto image, images)
        ui->listWidget->addItem(new QListWidgetItem(QIcon(image.path() + '/' + image.fileName()),image.fileName()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

