#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include <QFileInfo>
#include <QDebug>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QIcon>
#include <QPixmap>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QFileInfo image,QWidget *parent = nullptr);
    ~Edit();

private:
    Ui::Edit *ui;
    QIcon* img;

};

#endif // EDIT_H
