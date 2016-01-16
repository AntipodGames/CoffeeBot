LIBS += -L/usr/local/lib/ -lX11  -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -lGL -lGLU

INCLUDEPATH += /usr/include/boost /usr/SFML-2.1/include


CONFIG += c++11
QT += widgets
QT += phonon

SOURCES += main.cpp \
    animatedmanager.cpp \
    animatedsprite.cpp \
    carte.cpp \
    datamanager.cpp \
    displaymanager.cpp \
    entite.cpp \
    environment.cpp \
    imagemanager.cpp \
    ingame.cpp \
    ingameui.cpp \
    qsfcanvas.cpp \
    qsfml.cpp \
    soundmanager.cpp \
    texturemanager.cpp \
    tzellipse.cpp \
    hero.cpp \
    binaryswitch.cpp \
    lightsource.cpp

HEADERS += \
    animatedmanager.h \
    animatedsprite.h \
    carte.h \
    datamanager.h \
    displaymanager.h \
    entite.h \
    environment.h \
    imagemanager.h \
    ingame.h \
    ingameui.h \
    qsfcanvas.h \
    qsfml.h \
    soundmanager.h \
    texturemanager.h \
    tzellipse.h \
    hero.h \
    binaryswitch.h \
    lightsource.h \
    gleffect.hpp

