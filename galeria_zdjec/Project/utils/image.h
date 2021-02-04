#ifndef IMAGE_H
#define IMAGE_H
#include <QFileInfo>
#include <QObject>



class Image
{
public:
    Image(QFileInfo image);
    QString getpath();
private:
    QString path;
};

#endif // IMAGE_H
