#include "imagefilter.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>


using namespace cv;
using namespace std;

bool is_pressed = false;
bool drawfree = true;
bool shaping = false;

Mat drawimage(500, 500, CV_8UC3,
          Scalar(255, 255, 255));

Mat image(500, 500, CV_8UC3,
          Scalar(255, 255, 255));

int brushSize = 5;
Scalar brushColor(255, 0, 0);

Point_<int> pb(-1, -1);
Point_<int> pn(0, 0);

void CallbackMouse (int event, int x, int y, int flags, void* userdata);

void OnSqrButtonClick(int state, void* userdata);

int main(int argc, char **argv)
{

    drawimage.copyTo(image);

    // Check if the image is created
    // successfully or not
    if (!image.data) {
        cout << "Could not open or "
                  << "find the image\n";

        return 0;
    }

    // Top Left Corner
    int pbx = 30;
    Point_<int> pt(30, 30);

    // Bottom Right Corner
    // Point_<int> pb(pbx, 255);

    int thickness = 2;

    // Drawing the Rectangle




    // while(pb.x < 490){
    //     pb.x ++;
    //     circle(image, pb, 5, Scalar(255, 0, 0), thickness, LINE_8, 1);
    //     rectangle(image, pt, pb,
    //               Scalar(255, 0, 0),
    //               thickness, LINE_8);
    // }

    //imwrite("/home/kamen/git/Cpp-paint/lenna2.png", image);
    // Show our image inside a window

    //WINDOW setup
    String windowTitle = "Paint";
    namedWindow(windowTitle, WINDOW_NORMAL);
    setMouseCallback(windowTitle, CallbackMouse, NULL);

    //create tracker
    //int tr1 = createTrackbar("PointTop", windowTitle, &pb.x, 500);
    int tr2 = createTrackbar("Brush Size", windowTitle, &brushSize, 100);

    //create buttons
    //createButton("Make Square", OnSqrButtonClick, NULL, 0, 0);
    //cout<< getBuildInformation() << endl;

    while(true){

        //input

        //draw

        if(shaping && pb.x != -1){
            rectangle(image, pb, pn,
                      brushColor,
                      brushSize, LINE_8);
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
            brushColor = Scalar(0, 0, 255);
        } else if (key == 'b'){
            brushColor = Scalar(255, 0, 0);
        }

        if(key == '1'){
            drawfree = true;
            shaping = false;

        } else if (key == '2'){
            drawfree = false;
            shaping = true;
        }

        //clean
         // image = Mat(500, 500, CV_8UC3,
         //             Scalar(255, 255, 255));
        drawimage.copyTo(image);
    }

    return 0;
}

void CallbackMouse (int event, int x, int y, int flags, void* userdata){

    if  ( event == EVENT_LBUTTONDOWN )
    {
        is_pressed = true;
        pb.x = x;
        pb.y = y;
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
                line(drawimage, pb, pn, brushColor, brushSize, LINE_8);
                pb.x = pn.x;
                pb.y = pn.y;
            } else if (shaping){
                // rectangle(image, pb, pn,
                //           brushColor,
                //           brushSize, LINE_8);
            }


        }

    }
    else if  ( event == EVENT_LBUTTONUP )
    {
        if(is_pressed){
            if(shaping){
                rectangle(drawimage, pb, pn,
                          brushColor,
                          brushSize, LINE_8);
                pb.x = -1;
                pb.y = -1;
                pn.x = -1;
                pn.y = -1;
            }
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
