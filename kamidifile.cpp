#include "kamidifile.h"

kaMidiFile::kaMidiFile(int tempo, int ticksPerQuarter)
{
    __tempo=tempo;
    __ticksPerQuarter=ticksPerQuarter;
    mtrkLength=0;
}

QByteArray kaMidiFile::writeFile()
{
    //Midi file format 0; 384 ticks/Quarter
    int i;
    QByteArray midiHeader(QByteArray::fromHex("4D 54 68 64 00 00 00 06 00 00 00 01 01 80 "));
    QByteArray midiTracks(QByteArray::fromHex("4D 54 72 6B"));

    mtrkLength+=0x15;
    midiHeader.append(midiTracks);
    for (i=3; i>=0; i--)
       midiHeader.append(QByteArray::fromRawData((char*) &mtrkLength+i,1 ));

    midiHeader.append(QByteArray::fromHex("00 FF 51 03"));
    //convert tempo to midi value
    __tempo =60000000 / __tempo;
    for (i=2; i>=0; i--)
       midiHeader.append(QByteArray::fromRawData((char*) &__tempo+i,1 ));
    midiHeader.append(QByteArray::fromHex(" 00 C0 00 00 C0 00 20 90 55 00"));
    midiHeader.append(trackArray);

    midiHeader.append(QByteArray::fromHex("00FF2F00"));
    return midiHeader;
}


void kaMidiFile::addNote(int note, int duration, int velocity)
{
    if (!(0<=note && note<=127 &&0<=velocity && velocity<=127))
            return;

    QByteArray noteOnEvent(QByteArray::fromHex("00"));
    QByteArray noteEventGeneral(QByteArray::fromHex("90"));
    noteEventGeneral.append(QByteArray::fromRawData((char*) &note,1));
    noteOnEvent.append(noteEventGeneral);
    noteOnEvent.append(QByteArray::fromRawData((char*) &velocity,1));
    mtrkLength+=4;

    trackArray.append(noteOnEvent);

    int numOfTicks=__ticksPerQuarter*4/duration;
    int leadingNumber =numOfTicks/128;
    numOfTicks=numOfTicks%128;
    QByteArray noteOffEvent;
    if (leadingNumber>0)
    {
        leadingNumber= leadingNumber|0x80;
        noteOffEvent.append((char *) &leadingNumber,1);
        mtrkLength+=1;
    }
    noteOffEvent.append((char*) &numOfTicks,1);
    noteOffEvent.append(noteEventGeneral);
    noteOffEvent.append(QByteArray::fromHex("00"));
    trackArray.append(noteOffEvent);
    mtrkLength+=4;

}
