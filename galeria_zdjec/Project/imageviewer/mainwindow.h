#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirIterator>
#include <QDir>
#include <QPixmap>
#include <QtDebug>
#include <QListWidgetItem>
#include <QStateMachine>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_listImages_itemDoubleClicked(QListWidgetItem *item);

    void on_pbNext_clicked();

    void on_pbBack_clicked();

signals:
    void imageDoubleClicked();


private:
    Ui::MainWindow *ui;
    std::vector<QFileInfo> imagesInfos;
    std::vector<QListWidgetItem> imagesItems;
    QListWidgetItem *currentImage;
};
#endif // MAINWINDOW_H
