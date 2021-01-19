#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirIterator>
#include <QDir>
#include <QPixmap>
#include <QtDebug>
#include <QListWidgetItem>
#include <QStateMachine>
#include <QTimer>

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

private slots:
    void on_listImages_itemDoubleClicked(QListWidgetItem *item);
    void on_pbNext_clicked();
    void on_pbBack_clicked();
    void showSlides();
    void exitSlides();
    void viewSlide();


signals:
    void imageDoubleClicked();

private:
    Ui::MainWindow *ui;
    std::vector<QFileInfo> imagesInfos;
    std::vector<QListWidgetItem> imagesItems;
    QListWidgetItem *currentImage;
    QTimer *timer;
};
#endif // MAINWINDOW_H
