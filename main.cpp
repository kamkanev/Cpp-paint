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


Mat canvas(1000, 1000, CV_8UC3,
           Scalar(255, 255, 255));

Mat drawimage(500, 500, CV_8UC3,
          Scalar(255, 255, 255));

Mat image(500, 500, CV_8UC3,
          Scalar(255, 255, 255));

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
    Point_<int> pb(pbx, 255);

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
    int tr1 = createTrackbar("PointTop", windowTitle, &pb.x, 500);
    cout<<tr1<<endl;

    //create buttons
    //createButton("Make Square", OnSqrButtonClick, NULL, 0, 0);
    //cout<< getBuildInformation() << endl;

    while(true){

        //input

        //draw

        rectangle(image, pt, pb,
                  Scalar(255, 0, 0),
                  thickness, LINE_8);

        circle(image, pb, 5, Scalar(255, 0, 0), thickness, LINE_8, 1);
        //show

        imshow(windowTitle , image);


        //update
        waitKey(1);

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
            circle(drawimage, Point(x, y), 5, Scalar(255, 0, 0), FILLED, LINE_8, 0);
        }

    }
    else if  ( event == EVENT_LBUTTONUP )
    {
        is_pressed = false;
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
