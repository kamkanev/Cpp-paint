QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++17
# CONFIG -= app_bundle
# CONFIG -= qt
CONFIG += link_pkgconfig
PKGCONFIG += opencv4

INCLUDEPATH += /usr/include/opencv4
#INCLUDEPATH += /home/kamen/miniconda3/include/opencv4/opencv2

#LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

# wxCXXFLAGS = $$system(wx-config --cxxflags --unicode=yes --debug=no)
# wxLinkOptions = $$system(wx-config --debug=no --libs --unicode=yes)
# LIBS += $$wxLinkOptions
# QMAKE_CXXFLAGS_RELEASE += $$wxCXXFLAGS
# QMAKE_CXXFLAGS_DEBUG += $$wxCXXFLAGS

SOURCES += \
        utils/brush/brush.cpp \
        utils/canvas/canvas.cpp \
        utils/tools/circletool.cpp \
        elements/p_element.cpp \
        utils/tools/freedrawing.cpp \
        utils/filters/imagefilter.cpp \
        utils/tools/linetool.cpp \
        main.cpp \
        utils/tools/rectdrawing.cpp \
        utils/tools/shapetool.cpp

HEADERS += \
    utils/brush/brush.h \
    utils/canvas/canvas.h \
    utils/tools/circletool.h \
    elements/p_element.h \
    utils/tools/freedrawing.h \
    utils/filters/imagefilter.h \
    utils/tools/linetool.h \
    utils/tools/rectdrawing.h \
    utils/tools/shapetool.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
