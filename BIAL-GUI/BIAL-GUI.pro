#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T11:52:54
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bialgui
TEMPLATE = app

QMAKE_CXXFLAGS += -O0 -Wno-unused-function -Wno-unused-parameter \
-I$$PWD/../bial/inc -I$$PWD/../bial/src -I$$PWD/../bial/lsh/inc \
-I$$PWD/../bial/cpplex/inc -I$$PWD/../bial/SLIC/inc -I$$PWD/../bial/zlib -DREAL_FLOAT -DBIAL_$(basename $(notdir $(@)))

QMAKE_CXXFLAGS += -DBIAL_EXPLICIT_LIB
QMAKE_CXXFLAGS_DEBUG -= -pipe
QMAKE_CXXFLAGS_RELEASE -= -pipe

win32{
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp

Release:DESTDIR = $$PWD/../build/win/release/lib
Release:OBJECTS_DIR = $$PWD/../build/win/release/obj

Debug:DESTDIR = $$PWD/../build/win/debug/lib
Debug:OBJECTS_DIR = $$PWD/../build/win/debug/obj
}

unix: !macx{
QMAKE_CXXFLAGS += -fopenmp -std=c++11
QMAKE_LFLAGS += -fopenmp -std=c++11
}

macx{
QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++11
QMAKE_LFLAGS += -stdlib=libc++

Release:DESTDIR = $$PWD/../build/mac/release/lib
Release:OBJECTS_DIR = $$PWD/../build/mac/release/obj

Debug:DESTDIR = $$PWD/../build/mac/debug/lib
Debug:OBJECTS_DIR = $$PWD/../build/mac/debug/obj
}

unix{
DESTDIR = $$PWD/../build/linux/lib
OBJECTS_DIR = $$PWD/../build/linux/obj
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/win/release/lib -lbial
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/win/debug/lib -lbial
else:unix: LIBS += -L$$PWD/../build/linux/lib -lbial

INCLUDEPATH += $$PWD/../bial/inc
DEPENDPATH += $$PWD/../bial/inc

CONFIG += c++17

LIBS += -lz

win32{
LIBS += -fopenmp
}

unix: !macx{
LIBS += -fopenmp
}

RESOURCES += \
    qrs/resources.qrc

FORMS += \
    ui/controlswidget.ui \
    ui/imagewidget.ui \
    ui/mainwindow.ui \
    ui/segmentationwidget.ui \
    ui/thumbswidget.ui \
    ui/dragdrop.ui \
    ui/functionalwidget.ui

HEADERS += \
    src/controller.h \
    src/controlswidget.h \
    src/defaulttool.h \
    src/dicomdir.h \
    src/displayformat.h \
    src/dragdrop.h \
    src/functionalwidget.h \
    src/gdcm.h \
    src/graphicsitem.h \
    src/graphicsscene.h \
    src/graphicsview.h \
    src/guiimage.h \
    src/imageviewer.h \
    src/imagewidget.h \
    src/label.h \
    src/mainwindow.h \
    src/pushbutton.h \
    src/scrollarea.h \
    src/segmentationtool.h \
    src/segmentationwidget.h \
    src/thumbnail.hpp \
    src/thumbswidget.h \
    src/tool.h \
    src/viewerinterface.h \
    thirdParty/qcustomplot.h

SOURCES += \
    src/controller.cpp \
    src/controlswidget.cpp \
    src/defaulttool.cpp \
    src/dicomdir.cpp \
    src/displayformat.cpp \
    src/dragdrop.cpp \
    src/functionalwidget.cpp \
    src/gdcm.cpp \
    src/graphicsitem.cpp \
    src/graphicsscene.cpp \
    src/graphicsview.cpp \
    src/guiimage.cpp \
    src/imageviewer.cpp \
    src/imagewidget.cpp \
    src/label.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/pushbutton.cpp \
    src/scrollarea.cpp \
    src/segmentationtool.cpp \
    src/segmentationwidget.cpp \
    src/thumbnail.cpp \
    src/thumbswidget.cpp \
    src/tool.cpp \
    thirdParty/qcustomplot.cpp

DISTFILES += \
    uncrustify.cfg