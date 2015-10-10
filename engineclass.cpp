#include "engineclass.h"
#include <QDebug>

engineClass::engineClass(QObject *parent) : QObject(parent)
{
 newPattern(12,5,100);
}

void engineClass::play()
{
player->playFile();
}
void engineClass::newPattern(int range, int numOfNotes, int tempo)
{
       testPattern=new chromaticPattern(range,numOfNotes, tempo);
       testOutput=testPattern->getMidi();
       file.setFileName("test.midi");
       if(!file.open(QIODevice::WriteOnly)) {
           //std::cerr <<"Fehler"
        qDebug() << QString("Fileopenerror");
       }
       out =new QDataStream(&file);
       out->setVersion(8);
       out->writeRawData(testOutput,testOutput.length());
       file.flush();
       fileInfo=QFileInfo(file);
       filePath=QString(fileInfo.absoluteFilePath());
       player=new backendPlayer(filePath);


       file.close();
}


