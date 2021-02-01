#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirIterator>
#include <QDir>
#include <QPixmap>
#include <QtDebug>
#include <QDebug>
#include <QListWidgetItem>
#include <QStateMachine>
#include <QTimer>
#include <QDate>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>
#include <memory>

#include "album.h"
#include "edit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void escPressEvent(QKeyEvent *event);
    void newView(QString text, int type);

private slots:
    void on_listImages_itemDoubleClicked(QListWidgetItem *item);
    void on_pbNext_clicked();
    void on_pbBack_clicked();
    void showSlides();
    void exitSlides();
    void viewSlide();
    void on_pushButton_2_clicked();

    void on_pbAddtoalbum_clicked();

    void on_AlbumListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pbEdit_clicked();

    void on_pbRotate_clicked();

    void on_actionBy_Date_triggered();

    void on_actionBy_Na_e_triggered();

    void on_actionBy_Type_triggered();

    void on_pushButton_3_clicked();

signals:
    void imageDoubleClicked();

protected:
    Ui::MainWindow *ui;
    std::vector<QFileInfo> imagesInfos;
    std::vector<QListWidgetItem> imagesItems;
    std::vector<QListWidgetItem> dirItem;
    std::vector<QString> dirPath;
    std::vector<QDir> AlbumList;
    QListWidgetItem *currentImage;
    QTimer *timer;
};
#endif // MAINWINDOW_H
