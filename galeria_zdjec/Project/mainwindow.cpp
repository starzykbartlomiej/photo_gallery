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
    QDirIterator itr(dir.path()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums",QDir::AllDirs| QDir::NoDotAndDotDot);
    while (itr.hasNext()) {
                AlbumList.push_back(itr.next());
    }
    foreach(auto album,AlbumList){
        auto item=new QListWidgetItem(album.dirName());
        ui->AlbumListWidget->addItem(album.dirName());
        dirItem.push_back(*item);
        dirPath.push_back(album.path());
    }
    while(it.hasNext())
    {
        it.next();
        int spr=1;
        if(it.fileInfo().isFile()){
        foreach(auto it2, dirPath){
            if(it.filePath()==it2+'/'+it.fileName()){
                spr=0;
                break;
            }
        }
            if(spr)
            imagesInfos.push_back(it.fileInfo());
        }
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
    //auto AddToAlbumState=new QState(stateMachine);

    startupState->assignProperty(ui->pbBack, "enabled", false);
    startupState->assignProperty(ui->pbExit, "enabled", false);
    startupState->assignProperty(ui->pbNext, "enabled", false);
    startupState->assignProperty(ui->pbRotate, "enabled", false);
    startupState->assignProperty(ui->pbSlidesShow, "enabled", false);
    startupState->assignProperty(ui->pbAddtoalbum,"enabled",false);
    startupState->assignProperty(ui->pbEdit,"enabled",false);
    startupState->assignProperty(ui->stackedWidget, "currentIndex", 1);
    startupState->assignProperty(ui->stackedWidget_2, "currentIndex", 0);

    openState->assignProperty(ui->pbBack, "enabled", true);
    openState->assignProperty(ui->pbExit, "enabled", true);
    openState->assignProperty(ui->pbNext, "enabled", true);
    openState->assignProperty(ui->pbRotate, "enabled", true);
    openState->assignProperty(ui->pbEdit,"enabled",true);
    openState->assignProperty(ui->pbSlidesShow, "enabled", true);
    openState->assignProperty(ui->pbAddtoalbum,"enabled",true);
    openState->assignProperty(ui->stackedWidget, "currentIndex", 0);

//    AddToAlbumState->assignProperty(ui->pbBack, "enabled", false);
//    AddToAlbumState->assignProperty(ui->pbExit, "enabled", false);
//    AddToAlbumState->assignProperty(ui->pbNext, "enabled", false);
//    AddToAlbumState->assignProperty(ui->pbRotate, "enabled", false);
//    AddToAlbumState->assignProperty(ui->pbSlidesShow, "enabled", false);
//    AddToAlbumState->assignProperty(ui->pbAddtoalbum,"enabled",true);
//    AddToAlbumState->assignProperty(ui->stackedWidget, "currentIndex", 1);
//    startupState->assignProperty(ui->stackedWidget_2, "currentIndex", 0);


//    slidesState->assignProperty(ui->stackedWidget_2, "currentIndex", 1);

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


void MainWindow::on_pushButton_2_clicked()
{
    QString albumName=ui->albumName->displayText();
    if(albumName==""){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Album must have name");
        messageBox.setFixedSize(500,200);
        return;
    }
    QString pathAlbum;
    QDir dir(QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums");
    qDebug() << dir.path();
    dir.setCurrent("/oop_2020_galeria_zdjec/galeria_zdjec/Albums");
    qDebug() << dir.path();
    QDir dir2(albumName);
    if(dir2.exists()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Album had been created befor");
        messageBox.setFixedSize(500,200);
    }else{
        dir.mkdir(dir2.dirName());
        AlbumList.push_back(dir2);
        auto item=new QListWidgetItem(dir2.dirName());
        ui->AlbumListWidget->addItem(dir2.dirName());
        dirItem.push_back(*item);
        ui->albumName->setText("");

    }
}

void MainWindow::on_pbAddtoalbum_clicked()
{
    QFileInfo wantToSave;
    foreach(auto f,imagesInfos){
        if(f.fileName()==currentImage->text())
            wantToSave=f;
    }
    QDir directory = QFileDialog::getExistingDirectory(this, tr("select directory"),QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums",QFileDialog::ShowDirsOnly);
    QFile::copy(wantToSave.path()+'/'+wantToSave.fileName(),directory.path()+'/'+wantToSave.fileName());


}



void MainWindow::on_AlbumListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QDir dir(QDir::homePath()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums/"+item->text());
    //QString imgPath=QFileDialog::getOpenFileName(this,tr("Open Image"), dir.path(), tr("Image Files (*.png *.jpg *.bmp)"));
//    if(imgPath==""){
//        return;
//    }
    //QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
//    while(it.hasNext()){
//        it.next();
//        qDebug()<<it.fileName();
//    }
    Album album(dir.path());
    album.setModal(false);
    album.exec();

}

void MainWindow::on_pbEdit_clicked()
{

    QFileInfo wantToEdit;
    foreach(auto f,imagesInfos){
        if(f.fileName()==currentImage->text())
            wantToEdit=f;
    }
    Edit edit(wantToEdit);
    edit.setModal(false);
    edit.exec();
    while(true){
        if(!edit.edit){
            if(edit.close()){
                qDebug()<<1;
                break;
            }
            continue;
        }else {
            QDir dir(QDir::home());
            QDir::setCurrent(dir.path());
            imagesInfos.clear();
            ui->listImages->clear();
            QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
            while(it.hasNext())
            {
                it.next();
                int spr=1;
                if(it.fileInfo().isFile()){
                foreach(auto it2, dirPath){
                    if(it.filePath()==it2+'/'+it.fileName()){
                        spr=0;
                        break;
                    }
                }
                    if(spr)
                    imagesInfos.push_back(it.fileInfo());
                }
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
            break;

        }
    }
}

void MainWindow::on_pbRotate_clicked()
{

}
//void Edit::on_pushButton_clicked()
//{
//        QString imagePath = QFileDialog::getSaveFileName(

//                        this,

//                        tr("Save File"),

//                        "",

//                        tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )

//                        );



//            *imageObject = image.toImage();
//            imageObject->save(imagePath+".jpg");
//            this->close();



//}
