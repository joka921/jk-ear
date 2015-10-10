#ifndef ENGINECLASS_H
#define ENGINECLASS_H

#include <QObject>
#include "chromaticpattern.h"
#include <QFile>
#include <QQmlContext>
#include <QFileInfo>
#include "backendplayer.h"
#include <QByteArray>

class engineClass : public QObject
{
    Q_OBJECT
public:
    explicit engineClass(QObject *parent = 0);

signals:

public slots:
    void newPattern(int range, int numOfNotes, int tempo);
    void play();


private:
    chromaticPattern* testPattern;
    QFile file;
    QByteArray testOutput;
    QDataStream* out;
    QFileInfo fileInfo;
    QString filePath;
    backendPlayer* player;

};

#endif // ENGINECLASS_H
