#include "file.h"

file::file()
{
    QDir dir(QDir::home());
    QDir::setCurrent(dir.path());
    QDirIterator it(dir.path(), {"*.jpg", "*.png"}, QDir::Files, QDirIterator::Subdirectories);
    QDirIterator itr(dir.path()+"/oop_2020_galeria_zdjec/galeria_zdjec/Albums",QDir::AllDirs| QDir::NoDotAndDotDot);
    while (itr.hasNext()) {
                albumList.push_back(itr.next());
    }
    foreach(auto album,albumList){
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

}
std::vector<QFileInfo> file::getFileList(){
    return imagesInfos;
}

