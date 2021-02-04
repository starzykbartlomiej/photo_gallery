#include "image.h"

Image::Image(QFileInfo image)
{
    path=image.filePath();
}
QString Image::getpath(){
    return this->path;
}
