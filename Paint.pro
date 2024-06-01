TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += link_pkgconfig
PKGCONFIG += opencv4

# INCLUDEPATH += /usr/include/opencv4
#INCLUDEPATH += /home/kamen/miniconda3/include/opencv4/opencv2

# LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

# wxCXXFLAGS = $$system(wx-config --cxxflags --unicode=yes --debug=no)
# wxLinkOptions = $$system(wx-config --debug=no --libs --unicode=yes)
# LIBS += $$wxLinkOptions
# QMAKE_CXXFLAGS_RELEASE += $$wxCXXFLAGS
# QMAKE_CXXFLAGS_DEBUG += $$wxCXXFLAGS

SOURCES += \
        imagefilter.cpp \
        main.cpp

HEADERS += \
    imagefilter.h
