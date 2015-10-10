#ifndef CHROMATICPATTERN_H
#define CHROMATICPATTERN_H

#include <kamidifile.h>
#include <QByteArray>
#include <QtGlobal>
#include <QDateTime>

class chromaticPattern
{
public:
    chromaticPattern(int range, int numOfNotes, int lowest=35, int octaves=1);
    QByteArray  getMidi();
    void changeSettings(int range, int numOfNotes, int lowest=35, int octaves=1);


private:
    void __createMidi();
    QByteArray __midiData;
    int __range;
    int __numOfNotes;
    int __lowest;
    int __octaves;

};

#endif // CHROMATICPATTERN_H
