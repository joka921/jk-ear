#ifndef KAMIDIFILE_H
#define KAMIDIFILE_H

#include <QByteArray>

class kaMidiFile
{
public:
    kaMidiFile(int tempo=100, int ticksPerQuarter=384);
    QByteArray writeFile();
    void addNote(int note, int duration, int velocity=100);


private:
    int mtrkLength;
    QByteArray trackArray;
    int __ticksPerQuarter;
    qint32 __tempo;


};

#endif // KAMIDIFILE_H
