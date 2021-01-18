#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/student/oop_2020_galeria_zdjec/galeria_zdjec/Project/photos/grandma.jpg");
    int width = ui->label_pic->width();
    int height = ui->label_pic->height();
    ui->label_pic->setAlignment(Qt::AlignCenter);
    ui->label_pic->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

