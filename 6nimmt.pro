TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    game/gamecard.cpp \
    game/gamecardcollection.cpp \
    game/gamesession.cpp \
    game/gameplayer.cpp \
    game/gamesessionturn.cpp \
    game/gamesessionplayercards.cpp \
    game/gamesessionplayerpenaltycards.cpp \
    game/game.cpp \
    game/gamedataprovider.cpp \
    game/gamesessionresult.cpp \
    game/gameresult.cpp \
    game/gamesessionrow.cpp \
    game/gamesessionrender.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    game/gamecard.h \
    game/gamecardcollection.h \
    game/gamesession.h \
    game/gameplayer.h \
    game/gamesessionturn.h \
    game/gamesessionplayercards.h \
    game/gamesessionplayerpenaltycards.h \
    game/game.h \
    game/gamedataprovider.h \
    game/gamestatus.h \
    game/gamesessionresult.h \
    game/gameresult.h \
    game/gamesessionrow.h \
    game/gamesessionstatus.h \
    game/gamesessionrender.h

