#-------------------------------------------------
#
# Project created by QtCreator 2019-06-21T00:02:48
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DtTools
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        homepage.cpp \
        musicplayer.cpp \
        qvideoplayer.cpp \
        texteditor.cpp \
        videoplayer.cpp

HEADERS += \
        homepage.h \
        musicplayer.h \
        qvideoplayer.h \
        texteditor.h \
        videoplayer.h

RESOURCES += \
    res.qrc
