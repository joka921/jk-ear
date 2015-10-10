#include "chromaticpattern.h"

chromaticPattern::chromaticPattern(int range, int numOfNotes, int lowest, int octaves)
{
    changeSettings(range, numOfNotes, lowest, octaves);
}

void chromaticPattern::__createMidi()
{
    kaMidiFile midiExt;
    qsrand( QDateTime::currentDateTime().toTime_t() );
    for (int i=0;i<__numOfNotes;i++)
    {
        midiExt.addNote(qrand()%__range+__lowest,4);
    }
    __midiData = midiExt.writeFile();
}

QByteArray chromaticPattern::getMidi()
{
    this->__createMidi();
    return __midiData;
}
void chromaticPattern::changeSettings(int range, int numOfNotes, int lowest, int octaves)
{
    __range=range;
    __numOfNotes=numOfNotes;
    __lowest=lowest;
    __octaves=octaves;
}


