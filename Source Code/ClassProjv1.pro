#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T14:42:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClassProjv1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

PRECOMPILED_HEADER = pch.h

CONFIG += -std=c++11 precompile_header

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    allshapes.cpp \
    circle.cpp \
    ellipse.cpp \
    line.cpp \
    polygon.cpp \
    polyline.cpp \
    shape.cpp \
    text.cpp \
    rectangle.cpp \
    square.cpp \
    canvas.cpp \
    qtconversions.cpp \
    parser.cpp \
    selectionsort.cpp

HEADERS += \
    allshapes.h \
    libraries.h \
    shape.h \
    circle.h \
    ellipse.h \
    line.h \
    polygon.h \
    polyline.h \
    rectangle.h \
    square.h \
    text.h \
    shape_list.h \
    vector.h \
    parser.h \
    shapeexception.h \
    qtconversions.h \
    mainwindow.h \
    canvas.h \
    pch.h \
    selectionsort.h \
    custommath.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    shapes.txt \
    Team Logo v2.png

RESOURCES += \
    teamlogo.qrc
