#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <utils/tools/shapetool.h>
#include <utils/tools/freedrawing.h>
#include <utils/tools/rectdrawing.h>
#include <utils/tools/linetool.h>
#include <utils/tools/circletool.h>

#include "utils/canvas/canvas.h"

#include <QWidget>
#include <QMouseEvent>
#include <QShortcut>
#include <QPushButton>
#include <QMenuBar>

#include <string>

#include <gui/qcanvas.h>
#include "include/QtColorWidgets/ColorDialog"

class SimpleWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimpleWindow(QWidget *parent = nullptr);
    static QImage MatToQPixmap(const cv::Mat &image);

protected:
    Canvas canvas = Canvas(500, 500, cv::Scalar(255, 255, 255));
    QCanvas* noteLabel = new QCanvas(this);

    FreeDrawing fd = FreeDrawing(true);
    RectDrawing rd = RectDrawing(true);
    CircleTool cl = CircleTool(true);
    LineTool lt = LineTool(true);

    ShapeTool* st = &fd;

    // QShortcut *scFreeDraw = new QShortcut(QKeySequence("Ctrl+Shift+F"), this);
    // QShortcut *scRectTool = new QShortcut(QKeySequence("Ctrl+Shift+R"), this);
    // QShortcut *scCircleTool = new QShortcut(QKeySequence("Ctrl+Shift+C"), this);
    // QShortcut *scLineTool = new QShortcut(QKeySequence("Ctrl+Shift+L"), this);

    // QShortcut *scUndo = new QShortcut(QKeySequence("Ctrl+Z"), this);
    // QShortcut *scRedo = new QShortcut(QKeySequence("Ctrl+Y"), this);

    QPushButton* fdBtn = new QPushButton("Free");
    QPushButton* rdBtn = new QPushButton("Rect");
    QPushButton* clBtn = new QPushButton("Circle");
    QPushButton* ltBtn = new QPushButton("Line");
    QPushButton* rgbBtn = new QPushButton("RGB");


    color_widgets::ColorDialog* clrPick = new color_widgets::ColorDialog(this);

    QMenuBar *qbar;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;

private:
    void createMenus();
    void createActions();

private slots:
    void update(){
        st->focus(canvas.getImage());

        noteLabel->setPixmap(QPixmap::fromImage(MatToQPixmap(canvas.getImage())));
        canvas.update();
    }

    void undo(){
        canvas.undo();
    }

    void redo(){
        canvas.redo();
    }

    void changeColor(QColor color){
        //qDebug() << color.red() << " " << fd.getBrush().getColor().val;
        int r, g, b;
        color.getRgb(&r, &g, &b);
        st->brushPointer->setColor(cv::Scalar(b,g,r));
    }

    void changeTool(bool clicked){

        if(!clicked){
            QPushButton *buttonWidget = qobject_cast<QPushButton*>(sender());
            if (!buttonWidget)
                return;

            if(buttonWidget->text().toStdString() == "Free"){
                st = &fd;

                //qDebug() << buttonWidget ->text();
            } else if(buttonWidget->text().toStdString() == "Rect"){
                st = &rd;
            }else if(buttonWidget->text().toStdString() == "Circle"){
                st = &cl;
            } else if (buttonWidget->text().toStdString() == "Line"){
                st = &lt;
            }

            // qDebug() << buttonWidget ->text() << " " << fdBtn->text();
        }

    }

    void onMousePressed(QMouseEvent *event) {
        st->updateTool(event->pos().x(), event->pos().y());
        // qDebug() << "Mouse Pressed at:" << st->getBrush().getMouse().x << " , " << st->getBrush().getMouse().y;

    }

    void onMouseMoved(QMouseEvent *event) {
        // qDebug() << "Mouse Moved to:" << event->pos();
        st->updateDraw(canvas.getDrawImage(), event->pos().x(), event->pos().y());
    }

    void onMouseReleased(QMouseEvent *event) {
        // qDebug() << "Mouse Released at:" << event->pos();
        canvas.addToHistory(st->draw(canvas.getDrawImage(), event->pos().x(), event->pos().y()));
        st->updateTool(-1, -1);
    }

    void newFile(){
        //activate dialog window
        canvas = Canvas(500, 500, cv::Scalar(255, 255, 255));
    }

    void saveFile(){
        //dialog where to save
        imwrite("test.jpg", canvas.getImage());
    }

    void exitWindow(){
        this->close();
    }
};

#endif // SIMPLEWINDOW_H
