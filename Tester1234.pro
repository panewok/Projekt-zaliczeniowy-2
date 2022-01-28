QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    obiekty.cpp \
    rozgrywka.cpp \
    rozgrywka123.cpp \
    tworzenie_postaci_123.cpp

HEADERS += \
    obiekty.h \
    rozgrywka.h \
    rozgrywka123.h \
    tworzenie_postaci_123.h

FORMS += \
    rozgrywka.ui \
    rozgrywka123.ui \
    tworzenie_postaci_123.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
