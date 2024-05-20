TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        barco.cpp \
        enemigo.cpp \
        main.cpp \
        movimiento.cpp \
        objeto.cpp \
        objrecolectable.cpp \
        obstaculotrampa.cpp \
        personajeprincipal.cpp

HEADERS += \
    barco.h \
    enemigo.h \
    movimiento.h \
    objeto.h \
    objrecolectable.h \
    obstaculotrampa.h \
    personajeprincipal.h
