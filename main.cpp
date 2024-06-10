#include "imagefilter.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "mainwindow.h"
#include <cmath>
#include "brush.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>


using namespace cv;
using namespace std;

bool is_pressed = false;
bool drawfree = true;
bool shaping = false;
bool circles = false;

int r = 0;

Mat drawimage(500, 500, CV_8UC3,
          Scalar(255, 255, 255));

Mat image(500, 500, CV_8UC3,
          Scalar(255, 255, 255));

//Point_<int> pb(-1, -1);
Point_<int> pn(0, 0);

void CallbackMouse (int event, int x, int y, int flags, void* userdata);

void OnSqrButtonClick(int state, void* userdata);

int main(int argc, char *argv[])
{

    drawimage.copyTo(image);
    // Check if the image is created
    // successfully or not
    if (!image.data) {
        cout << "Could not open or "
                  << "find the image\n";

        return 0;
    }

    //imwrite("/home/kamen/git/Cpp-paint/lenna2.png", image);
    // Show our image inside a window

    //create brush
    Brush br1 = Brush();

    //WINDOW setup
    String windowTitle = "Paint";
    namedWindow(windowTitle, WINDOW_NORMAL);
    setMouseCallback(windowTitle, CallbackMouse, &br1);


    //create tracker
    //int tr1 = createTrackbar("PointTop", windowTitle, &pb.x, 500);
    int tr2 = createTrackbar("Brush Size", windowTitle, br1.sizePointer, 100);

    //create buttons
    //createButton("Make Square", OnSqrButtonClick, NULL, 0, 0);
    //cout<< getBuildInformation() << endl;

    //Q Apllication
    //QApplication app(argc, argv);
    //MainWindow mw;
    //mw.show();

    while(true){

        //input

        //draw

        if(shaping && br1.getMouse().x != -1){
            rectangle(image, br1.getMouse(), pn,
                      br1.getColor(),
                      br1.getSize(), br1.getLineType());
        }

        if(circles && br1.getMouse().x != -1){
            circle(image, br1.getMouse(), r, br1.getColor(), br1.getSize(), br1.getLineType());
        }

        // circle(image, pb, 5, Scalar(255, 0, 0), thickness, LINE_8, 1);
        //show

        imshow(windowTitle , image);


        //update
        char key = waitKey(1);

        if(key == 27){ //ESC
            break;
        }

        if(key == 'r'){
            br1.setColor(Scalar(0, 0, 255));
        } else if (key == 'b'){
            br1.setColor(Scalar(255, 0, 0));
        }

        if(key == '1'){
            drawfree = true;
            shaping = false;
            circles = false;

        } else if (key == '2'){
            drawfree = false;
            shaping = true;
            circles = false;

        } else if (key == '3'){
            drawfree = false;
            shaping = false;
            circles = true;
        }

        //clean
         // image = Mat(500, 500, CV_8UC3,
         //             Scalar(255, 255, 255));
        drawimage.copyTo(image);
    }

    return 0; //app.exec();
}

void CallbackMouse (int event, int x, int y, int flags, void* userdata){

    Brush* brush = reinterpret_cast<Brush*>(userdata);

    if  ( event == EVENT_LBUTTONDOWN )
    {
        is_pressed = true;
        brush->updateMouse(x, y);
        pn.x = x;
        pn.y = y;
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
            pn.x = x;
            pn.y = y;
            // circle(drawimage, Point(x, y), brushSize, brushColor, FILLED, LINE_8, 0);
            if(drawfree){
                line(drawimage, brush->getMouse(), pn, brush->getColor(), brush->getSize(), brush->getLineType());
                brush->updateMouse(pn.x, pn.y);
            } else if (shaping){
                // rectangle(image, pb, pn,
                //           brushColor,
                //           brushSize, LINE_8);
            } else if (circles){
                r = sqrt(pow(fabs(brush->getMouse().x - pn.x),2) + pow(fabs(brush->getMouse().y - pn.y),2));
            }


        }

    }
    else if  ( event == EVENT_LBUTTONUP )
    {
        if(is_pressed){
            if(shaping){
                rectangle(drawimage, brush->getMouse(), pn, brush->getColor(), brush->getSize(), brush->getLineType());
            } else if(circles){
                circle(drawimage, brush->getMouse(), r, brush->getColor(), brush->getSize(), brush->getLineType());
                r = 0;
            }
            brush->updateMouse(-1, -1);
            pn.x = -1;
            pn.y = -1;
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
