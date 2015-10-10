#include "kamidifile.h"

kaMidiFile::kaMidiFile(int tempo, int ticksPerQuarter)
{
    __tempo=tempo;
    __ticksPerQuarter=ticksPerQuarter;
    mtrkLength=0;
}

QByteArray kaMidiFile::writeFile()
{
  // for the moment, use generic header so that it works

    /*
    //Write Midi Header
    QByteArray midiHeader("MThd");
    midiHeader.append(QByteArray::fromHex("00000006"));
    //only format 0 at the moment;
    midiHeader.append(QByteArray::fromHex("0000"));
    //only one Track
    midiHeader.append(QByteArray::fromHex("0001"));
    //Midi Delta Time Division, fix value of 384 at the moment;
    midiHeader.append(QByteArray::fromHex("0180"));

    //Write (only) Track, needs to be BigEndian for File;
    QByteArray trackOne("MTrk");

    mtrkLength+=11; //add Bytes from Tempo and Final event below
    for (int i=3; i>=0; i--)
       trackOne.append(QByteArray::fromRawData((char*) &mtrkLength+i,1 ));

    //Add Tempo information
    trackOne.append(QByteArray::fromHex("00FF5103"));

    //Convert to Microseconds per Beat and change Endianess (3 Byte encoding)
    qint32 tempoMicrosec = 60000000/__tempo;
    for (int i=2; i>=0; i--)
       trackOne.append(QByteArray::fromRawData((char*) &tempoMicrosec+i,1 ));


    midiHeader.append(trackOne);
    */

    QByteArray midiHeader(QByteArray::fromHex("4D 54 68 64 00 00 00 06 00 01 00 02 01 80 4D 54 72 6B 00 00 00 53 00 FF 03 0D 63 6F 6E 74 72 6F 6C 20 74 72 61 63 6B 00 FF 01 09 63 72 65 61 74 6F 72 3A 20 00 FF 01 1E 47 4E 55 20 4C 69 6C 79 50 6F 6E 64 20 32 2E 31 36 2E 32 20 20 20 20 20 20 20 20 20 20 20 00 FF 58 04 04 02 12 08 00 FF 51 03 09 27 C0 00 FF 2F 00 4D 54 72 6B"));
    mtrkLength+=0x39;
    for (int i=3; i>=0; i--)
       midiHeader.append(QByteArray::fromRawData((char*) &mtrkLength+i,1 ));

    midiHeader.append(QByteArray::fromHex("00 FF 03 0F 3A 75 6E 69 71 75 65 43 6F 6E 74 65 78 74 30 00 C0 00 00 C0 00 00 FF 04 0E 61 63 6F 75 73 74 69 63 20 67 72 61 6E 64 00 FF 59 02 00 00 20 90 55 00"));
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
