#include <QApplication>
#include <QQmlApplicationEngine>
#include "chromaticpattern.h"
#include <QFile>
#include <QQmlContext>
#include <QFileInfo>
#include "backendplayer.h"
#include <QObject>
#include "engineclass.h"



int main(int argc, char *argv[])
{

    engineClass*  logicEngine= new engineClass;
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = new QQmlContext(engine.rootContext());
    //context->setContextProperty("currentDir",QApplication::applicationDirPath());


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(engine.rootObjects().first(),SIGNAL(playExtern()),logicEngine,SLOT(play()));
    QObject::connect(engine.rootObjects().first(),SIGNAL(newPattern(int,int, int)),logicEngine,SLOT(newPattern(int,int,int)));
    // QObject::connect(engine.rootObjects().first(),SIGNAL(stopExtern()),&playerAndroidTest,SLOT(stop()));
    logicEngine->newPattern(3,3,100);

    return app.exec();

}
