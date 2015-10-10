#ifndef BACKENDPLAYER_H
#define BACKENDPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QThread>
#if defined Q_OS_ANDROID
#include <QtAndroidExtras/QAndroidJniObject>
#endif

class backendPlayer : public QObject
{
    Q_OBJECT
public:
    explicit backendPlayer(QString file_Path,QObject *parent = 0);
    QMediaPlayer* player;
signals:

public slots:
    void playFile();

private:
    QString m_filepath;


};

#endif // BACKENDPLAYER_H
