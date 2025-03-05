#include "imagefilter.h"
#include <iostream>
#include <opencv2/opencv.hpp>
//#include "mainwindow.h"
#include <cmath>
#include "brush.h"
#include "canvas.h"
#include "freedrawing.h"
#include "rectdrawing.h"
#include "circletool.h"
#include "linetool.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>


using namespace cv;
using namespace std;

bool is_pressed = false;

Canvas canvas = Canvas(500, 500, Scalar(255, 255, 255));
FreeDrawing fd = FreeDrawing(true);
RectDrawing rd = RectDrawing(true);
CircleTool cl = CircleTool(true);
LineTool lt = LineTool(true);

ShapeTool* st = &fd;

void CallbackMouse (int event, int x, int y, int flags, void* userdata);

void OnSqrButtonClick(int state, void* userdata);

int main(int argc, char *argv[])
{

    // Check if the image is created
    // successfully or not
    if (!canvas.getImage().data) {
        cout << "Could not open or "
                  << "find the image\n";

        return 0;
    }

    //imwrite("/home/kamen/git/Cpp-paint/lenna2.png", image);
    // Show our image inside a window

    int fWid = 600, fHei = 1000;
    cout<<"Enter Width and Height:" << endl;
    cout<<"Width: ";
    cin>> fWid;
    cout<<"Height: ";
    cin>> fHei;

    // drawimage = Mat(fHei, fWid, CV_8UC3,
    //                 Scalar(255, 255, 255));
    // drawimage.copyTo(image);

    //WINDOW setup
    String windowTitle = "Paint";
    namedWindow(windowTitle, WINDOW_NORMAL);
    setMouseCallback(windowTitle, CallbackMouse);//&br1


    //create tracker
    //int tr1 = createTrackbar("PointTop", windowTitle, &pb.x, 500);
    int tr2 = createTrackbar("Brush Size", windowTitle, st->getBrush().sizePointer, 100);

    //create buttons
    //createButton("Make Square", OnSqrButtonClick, NULL, 0, 0);
    //cout<< getBuildInformation() << endl;

    //Q Apllication
    //QApplication app(argc, argv);
    //MainWindow mw;
    //mw.show();

    char key = 0;

    while(key != 27 && getWindowProperty(windowTitle, WINDOW_AUTOSIZE) != -1){ //ESC or close window

        //input

        //draw focus
        st->focus(canvas.getImage());

        //show
        imshow(windowTitle , canvas.getImage());


        //update
        key = waitKey(10);

        if(key == 'r'){
            st->brushPointer->setColor(Scalar(0, 0, 255));
        } else if (key == 'b'){
            st->brushPointer->setColor(Scalar(255, 0, 0));
        }

        if(key == '1'){
            st = &fd;

        } else if (key == '2'){
            st = &rd;

        } else if (key == '3'){
            st = &cl;
        } else if (key == '4'){
            st = &lt;
        }

        //clean
         // image = Mat(500, 500, CV_8UC3,
         //             Scalar(255, 255, 255));
        //drawimage.copyTo(image);
        canvas.update();
    }

    return 0; //app.exec();
}

void CallbackMouse (int event, int x, int y, int flags, void* userdata){

    //Brush* brush = reinterpret_cast<Brush*>(userdata);

    if  ( event == EVENT_LBUTTONDOWN )
    {
        is_pressed = true;
        st->updateTool(x, y);
        //cout << "Left button of the mouse is pressed - position (" << x << ", " << y << ")" << endl;

    }
    else if  ( event == EVENT_RBUTTONDOWN )
    {
        //cout << "Right button of the mouse is pressed - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_MBUTTONDOWN )
    {
       // cout << "Middle button of the mouse is pressed - position (" << x << ", " << y << ")" << endl;
    }
    else if ( event == EVENT_MOUSEMOVE )
    {
       // cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
        if (is_pressed){

            st->updateDraw(canvas.getDrawImage(), x, y);


        }

    }
    else if  ( event == EVENT_LBUTTONUP )
    {
        if(is_pressed){

            st->draw(canvas.getDrawImage(), x, y);

            st->updateTool(-1, -1);
            is_pressed = false;
        }
      //  cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_RBUTTONUP )
    {
      //  cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_MBUTTONUP )
    {
      //  cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }

}

void OnSqrButtonClick(int state, void* userdata){
    cout<<"Button state: " << state << endl;
}
