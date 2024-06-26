QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemy.cpp \
    game.cpp \
    gold.cpp \
    ground.cpp \
    levels.cpp \
    main.cpp \
    mainwindow.cpp \
    movement.cpp \
    player.cpp \
    seatrap.cpp \
    seatreasure.cpp \
    ship.cpp \
    sprite.cpp \
    trap.cpp

HEADERS += \
    enemigo.h \
    enemy.h \
    game.h \
    gold.h \
    ground.h \
    levels.h \
    mainwindow.h \
    movement.h \
    player.h \
    seatrap.h \
    seatreasure.h \
    ship.h \
    sprite.h \
    trap.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    imagenes.qrc
