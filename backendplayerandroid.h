#ifndef BACKENDPLAYERANDROID_H
#define BACKENDPLAYERANDROID_H
#include <QtAndroidExtras/QAndroidJniObject>


#include <QObject>

class backendPlayerAndroid : public QObject
{
    Q_OBJECT
public:
    explicit backendPlayerAndroid(QString file_Path, QObject *parent = 0);


signals:

public slots:
    void play();
    void stop();

private:
    QAndroidJniObject mediaPlayer;
    QString m_filename;
};

#endif // BACKENDPLAYERANDROID_H
