TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11 -Wno-unused-local-typedef

SOURCES += main.cpp \
    lib/windows/gamewindow/cardstate/cardstate.cpp \
    lib/windows/gamewindow/cardstate/cardstateactive.cpp \
    lib/windows/gamewindow/cardstate/cardstatestatic.cpp \
    lib/windows/gamewindow/card.cpp \
    lib/windows/gamewindow/playercardscontainer.cpp \
    lib/windows/gamewindow/playerpoints.cpp \
    lib/windows/gamewindow/row.cpp \
    lib/windows/gamewindow/rowcontainer.cpp \
    lib/windows/gamewindow/temporarycardscontainer.cpp \
    lib/windows/gamewindow.cpp \
    lib/windows/mainwindow.cpp \
    lib/ownexception.cpp \
    lib/server/gamedata.cpp \
    lib/server/serverloader.cpp \
    lib/application.cpp

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
    lib/application.h \
    lib/main.h \
    lib/server/gamedata.h \
    lib/server/serverloader.h \
    lib/windows/gamewindow/cardstate/cardstate.h \
    lib/windows/gamewindow/cardstate/cardstateactive.h \
    lib/windows/gamewindow/cardstate/cardstatestatic.h \
    lib/windows/gamewindow/card.h \
    lib/windows/gamewindow/playercardscontainer.h \
    lib/windows/gamewindow/playerpoints.h \
    lib/windows/gamewindow/row.h \
    lib/windows/gamewindow/rowcontainer.h \
    lib/windows/gamewindow/temporarycardscontainer.h \
    lib/windows/gamewindow.h \
    lib/windows/mainwindow.h

DISTFILES +=
