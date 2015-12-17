TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
    lib/mainwindow.cpp \
    lib/ownexception.cpp \
    lib/gamewindow.cpp \
    lib/serverloader.cpp \
    lib/gamedata.cpp \
    lib/row.cpp \
    lib/rowcontainer.cpp \
    lib/card.cpp \
    lib/playercardscontainer.cpp \
    lib/playerpoints.cpp \
    lib/temporarycardscontainer.cpp \
    lib/cardstate.cpp \
    lib/cardstatestatic.cpp \
    lib/cardstateactive.cpp

RESOURCES += \
    static/resources.qrc

INCLUDEPATH += /usr/local/Cellar/boost/1.58.0/include
LIBS += -L/usr/local/Cellar/boost/1.58.0/lib
LIBS += -lboost_system-mt -lboost_filesystem-mt

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    lib/mainwindow.h \
    lib/ownexception.h \
    lib/gamewindow.h \
    lib/serverloader.h \
    lib/gamedata.h \
    lib/row.h \
    lib/rowcontainer.h \
    lib/card.h \
    lib/playercardscontainer.h \
    lib/playerpoints.h \
    lib/temporarycardscontainer.h \
    lib/cardstate.h \
    lib/cardstatestatic.h \
    lib/cardstateactive.h

DISTFILES +=
