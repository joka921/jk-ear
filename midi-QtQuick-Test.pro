TEMPLATE = app

QT += qml quick widgets multimedia

SOURCES += main.cpp \
    kamidifile.cpp \
    chromaticpattern.cpp \
    backendplayer.cpp \
    engineclass.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    kamidifile.h \
    chromaticpattern.h \
    backendplayer.h \
    engineclass.h


OTHER_FILES +=

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

DISTFILES +=

