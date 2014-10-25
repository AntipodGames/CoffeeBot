LIBS *= -L"C:/Users/Hippolyte/C++/SFML-master-build/lib" -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += C:/Users/Hippolyte/C++/SFML-master/include
DEPENDPATH += C:/Users/Hippolyte/C++/SFML-master/include

QT+= core \
    gui \
    phonon

HEADERS += \
    ../animatedmanager.h \
    ../animatedsprite.h \
    ../carte.h \
    ../datamanager.h \
    ../displaymanager.h \
    ../entite.h \
    ../environment.h \
    ../hero.h \
    ../imagemanager.h \
    ../ingame.h \
    ../ingameui.h \
    ../qsfcanvas.h \
    ../qsfml.h \
    ../soundmanager.h \
    ../texturemanager.h \
    ../tzellipse.h

SOURCES += \
    ../animatedmanager.cpp \
    ../animatedsprite.cpp \
    ../carte.cpp \
    ../datamanager.cpp \
    ../displaymanager.cpp \
    ../entite.cpp \
    ../environment.cpp \
    ../hero.cpp \
    ../imagemanager.cpp \
    ../ingame.cpp \
    ../ingameui.cpp \
    ../main.cpp \
    ../qsfcanvas.cpp \
    ../qsfml.cpp \
    ../soundmanager.cpp \
    ../texturemanager.cpp \
    ../tzellipse.cpp
