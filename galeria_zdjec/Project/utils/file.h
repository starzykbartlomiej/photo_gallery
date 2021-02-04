#ifndef FILE_H
#define FILE_H
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

class file
{
public:
    file();
    std::vector<QFileInfo> getFileList();
private:
     std::vector<QFileInfo> imagesInfos;
     std::vector<QDir> albumList;
     std::vector<QString> dirPath;
};

#endif // FILE_H
