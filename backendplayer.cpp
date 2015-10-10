#include "backendplayer.h"


backendPlayer::backendPlayer(QString filePath, QObject *parent) : QObject(parent)
{
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(filePath));
    m_filepath =filePath;
}

void backendPlayer::playFile()
{
    player->stop();
    //delete player;
    //player= new QMediaPlayer;
    //player->setMedia(QUrl::fromLocalFile(m_filepath));
   //player->setPosition(0);
    QThread::msleep(500);

    player->play();
}

