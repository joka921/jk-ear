#include "backendplayerandroid.h"

backendPlayerAndroid::backendPlayerAndroid(QString file_Path,QObject *parent) : QObject(parent)
{

    //jstring javaFilename=QAndroidJniObject::fromString("test");
    QAndroidJniObject javaFilename = QAndroidJniObject::fromString(file_Path);
//mediaPlayer =QAndroidJniObject("org/qtproject/example/mediaplayer/javamediaplayer","(Ljava/lang/String;)Lorg/qtproject/example/mediaplayer/javamediaplayer",javaFilename.object<jstring>());
QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/mediaplayer/javamediaplayer","create","(Ljava/lang/String;)Lorg/qtproject/example/mediaplayer/javamediaplayer",javaFilename.object<jstring>());

    m_filename=file_Path;

}

void backendPlayerAndroid::play()
{

    //mediaPlayer.callMethod<void>("pleray");

    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/mediaplayer/javamediaplayer","play");
}

void backendPlayerAndroid::stop()
{
   // mediaPlayer->callObjectMethod<void>("stop");
}

