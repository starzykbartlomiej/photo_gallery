#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "utils.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displacement = Displacement();
    speed = Speed();
    acceleration = Acceleration();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString xString = ui->displacementValue->text();;
    int x = xString.toFloat();
    displacement.set(x);
    speed.notify(x);
    acceleration.notify(x);

    ui->lcdSpeed->display(speed.get());
    ui->lcdAcceleration->display(acceleration.get());
}
