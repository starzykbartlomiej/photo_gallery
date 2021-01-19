#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(viewSlide()));

    //thumbnails
    QDir dir(QDir::home());
    QDir::setCurrent(dir.path());
    QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);

    while(it.hasNext())
    {
        it.next();
        if(it.fileInfo().isFile())
            imagesInfos.push_back(it.fileInfo());
    }
    ui->listImages->setViewMode(QListWidget::IconMode);
    ui->listImages->setIconSize(QSize(80,80));
    ui->listImages->setResizeMode(QListWidget::Adjust);
    foreach(auto imageinfo, imagesInfos)
    {
        auto item = new QListWidgetItem(QIcon(imageinfo.path() + '/' + imageinfo.fileName()),imageinfo.fileName());
        ui->listImages->addItem(item);
        imagesItems.push_back(*item);
    }

    //states
    auto stateMachine = new QStateMachine(this);
    auto startupState = new QState(stateMachine);
    auto openState = new QState(stateMachine);
    auto slidesState = new QState(stateMachine);

    startupState->assignProperty(ui->pbBack, "enabled", false);
    startupState->assignProperty(ui->pbExit, "enabled", false);
    startupState->assignProperty(ui->pbNext, "enabled", false);
    startupState->assignProperty(ui->pbRotate, "enabled", false);
    startupState->assignProperty(ui->pbSlidesShow, "enabled", false);
    startupState->assignProperty(ui->stackedWidget, "currentIndex", 1);
    startupState->assignProperty(ui->stackedWidget_2, "currentIndex", 0);

    openState->assignProperty(ui->pbBack, "enabled", true);
    openState->assignProperty(ui->pbExit, "enabled", true);
    openState->assignProperty(ui->pbNext, "enabled", true);
    openState->assignProperty(ui->pbRotate, "enabled", true);
    openState->assignProperty(ui->pbSlidesShow, "enabled", true);
    openState->assignProperty(ui->stackedWidget, "currentIndex", 0);

    slidesState->assignProperty(ui->stackedWidget_2, "currentIndex", 1);

    connect(slidesState, SIGNAL(entered()), this, SLOT(showSlides()));
    connect(startupState, SIGNAL(entered()), this, SLOT(exitSlides()));

    startupState->addTransition(this, SIGNAL(imageDoubleClicked()), openState);
    openState->addTransition(ui->pbExit, SIGNAL(clicked()), startupState);
    openState->addTransition(ui->pbSlidesShow, SIGNAL(clicked()), slidesState);
    slidesState->addTransition(ui->pbFullScreenExit, SIGNAL(clicked()), startupState);


    stateMachine->setInitialState(startupState);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listImages_itemDoubleClicked(QListWidgetItem *item)
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusbar->clearMessage();
    ui->statusbar->showMessage(item->text());

    currentImage = item;

    int width = ui->label_picture->width();
    int height = ui->label_picture->height();
    ui->label_picture->setAlignment(Qt::AlignCenter);
    auto pix = item->icon().pixmap(QSize(width, height));
    ui->label_picture->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));

    emit imageDoubleClicked();
}

void MainWindow::on_pbNext_clicked()
{
    unsigned long index = 0;
    for(unsigned long i=0; i<imagesItems.size()-1; i++)
    {
        if(currentImage->text() == imagesItems[i].text())
            index = i+1;
    }

    ui->statusbar->clearMessage();
    ui->statusbar->showMessage(imagesItems[index].text());

    currentImage = &(imagesItems[index]);
    int width = ui->label_picture->width();
    int height = ui->label_picture->height();
    ui->label_picture->setAlignment(Qt::AlignCenter);
    auto pix = imagesItems[index].icon().pixmap(QSize(width, height));
    ui->label_picture->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));
}

void MainWindow::on_pbBack_clicked()
{
    unsigned long index = imagesItems.size()-1;
    for(unsigned long i=1; i<imagesItems.size(); i++)
    {
        if(currentImage->text() == imagesItems[i].text())
            index = i-1;
    }

    ui->statusbar->clearMessage();
    ui->statusbar->showMessage(imagesItems[index].text());

    currentImage = &(imagesItems[index]);
    int width = ui->label_picture->width();
    int height = ui->label_picture->height();
    ui->label_picture->setAlignment(Qt::AlignCenter);
    auto pix = imagesItems[index].icon().pixmap(QSize(width, height));
    ui->label_picture->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));
}

void MainWindow::showSlides()
{
    int width = ui->labelSlide->width();
    int height = ui->labelSlide->height();
    ui->labelSlide->setAlignment(Qt::AlignCenter);
    auto pix = currentImage->icon().pixmap(QSize(width, height));
    ui->labelSlide->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));

    QWidget::showFullScreen();
    timer->start(3000);
}
void MainWindow::viewSlide()
{
    unsigned long index = 0;
    for(unsigned long i=0; i<imagesItems.size()-1; i++)
    {
        if(currentImage->text() == imagesItems[i].text())
            index = i+1;
    }

    ui->statusbar->clearMessage();
    ui->statusbar->showMessage(imagesItems[index].text());

    currentImage = &(imagesItems[index]);
    int width = ui->labelSlide->width();
    int height = ui->labelSlide->height();
    ui->labelSlide->setAlignment(Qt::AlignCenter);
    auto pix = imagesItems[index].icon().pixmap(QSize(width, height));
    ui->labelSlide->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));
}
void MainWindow::exitSlides()
{
    timer->stop();
    QWidget::showNormal();
}
