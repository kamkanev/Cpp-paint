TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += link_pkgconfig
PKGCONFIG += opencv4

INCLUDEPATH += /usr/include/opencv4

LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

SOURCES += \
        imagefilter.cpp \
        main.cpp

HEADERS += \
    imagefilter.h
