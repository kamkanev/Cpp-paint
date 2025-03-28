######################################################################
# Automatically generated by qmake (3.1) Fri Mar 28 17:25:10 2025
######################################################################

TEMPLATE = app
TARGET = Cpp-paint
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += ui_color_dialog.h \
           ui_color_palette_widget.h \
           ui_mainwindow.h \
           elements/circle_element.h \
           elements/line_element.h \
           elements/p_element.h \
           elements/poly_element.h \
           elements/rect_element.h \
           gui/qcanvas.h \
           gui/simplewindow.h \
           gui/dialog/newdielog.h \
           include/QtColorWidgets/abstract_widget_list.hpp \
           include/QtColorWidgets/bound_color_selector.hpp \
           include/QtColorWidgets/color_2d_slider.hpp \
           include/QtColorWidgets/color_delegate.hpp \
           include/QtColorWidgets/color_dialog.hpp \
           include/QtColorWidgets/color_line_edit.hpp \
           include/QtColorWidgets/color_list_widget.hpp \
           include/QtColorWidgets/color_names.hpp \
           include/QtColorWidgets/color_palette.hpp \
           include/QtColorWidgets/color_palette_model.hpp \
           include/QtColorWidgets/color_palette_widget.hpp \
           include/QtColorWidgets/color_preview.hpp \
           include/QtColorWidgets/color_selector.hpp \
           include/QtColorWidgets/color_utils.hpp \
           include/QtColorWidgets/color_wheel.hpp \
           include/QtColorWidgets/color_wheel_private.hpp \
           include/QtColorWidgets/colorwidgets_global.hpp \
           include/QtColorWidgets/gradient_delegate.hpp \
           include/QtColorWidgets/gradient_editor.hpp \
           include/QtColorWidgets/gradient_helper.hpp \
           include/QtColorWidgets/gradient_list_model.hpp \
           include/QtColorWidgets/gradient_slider.hpp \
           include/QtColorWidgets/harmony_color_wheel.hpp \
           include/QtColorWidgets/hue_slider.hpp \
           include/QtColorWidgets/qt_compatibility.hpp \
           include/QtColorWidgets/swatch.hpp \
           utils/brush/brush.h \
           utils/canvas/canvas.h \
           utils/filters/imagefilter.h \
           utils/tools/circletool.h \
           utils/tools/freedrawing.h \
           utils/tools/linetool.h \
           utils/tools/rectdrawing.h \
           utils/tools/shapetool.h
FORMS += src/QtColorWidgets/color_dialog.ui \
         src/QtColorWidgets/color_palette_widget.ui
SOURCES += main.cpp \
           elements/circle_element.cpp \
           elements/line_element.cpp \
           elements/p_element.cpp \
           elements/poly_element.cpp \
           elements/rect_element.cpp \
           gui/qcanvas.cpp \
           gui/simplewindow.cpp \
           gui/dialog/newdielog.cpp \
           src/QtColorWidgets/abstract_widget_list.cpp \
           src/QtColorWidgets/bound_color_selector.cpp \
           src/QtColorWidgets/color_2d_slider.cpp \
           src/QtColorWidgets/color_delegate.cpp \
           src/QtColorWidgets/color_dialog.cpp \
           src/QtColorWidgets/color_line_edit.cpp \
           src/QtColorWidgets/color_list_widget.cpp \
           src/QtColorWidgets/color_names.cpp \
           src/QtColorWidgets/color_palette.cpp \
           src/QtColorWidgets/color_palette_model.cpp \
           src/QtColorWidgets/color_palette_widget.cpp \
           src/QtColorWidgets/color_preview.cpp \
           src/QtColorWidgets/color_selector.cpp \
           src/QtColorWidgets/color_utils.cpp \
           src/QtColorWidgets/color_wheel.cpp \
           src/QtColorWidgets/gradient_editor.cpp \
           src/QtColorWidgets/gradient_list_model.cpp \
           src/QtColorWidgets/gradient_slider.cpp \
           src/QtColorWidgets/harmony_color_wheel.cpp \
           src/QtColorWidgets/hue_slider.cpp \
           src/QtColorWidgets/swatch.cpp \
           utils/brush/brush.cpp \
           utils/canvas/canvas.cpp \
           utils/filters/imagefilter.cpp \
           utils/tools/circletool.cpp \
           utils/tools/freedrawing.cpp \
           utils/tools/linetool.cpp \
           utils/tools/rectdrawing.cpp \
           utils/tools/shapetool.cpp
RESOURCES += resources/QtColorWidgets/color_widgets.qrc
