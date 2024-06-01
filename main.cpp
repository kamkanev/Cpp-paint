#include "imagefilter.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image(500, 500, CV_8UC3,
              Scalar(255, 255, 255));

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
    namedWindow("Output", WINDOW_NORMAL);

    int tr1 = createTrackbar("PointTop","Output", &pb.x, 500);
    cout<<tr1<<endl;

    while(true){

        rectangle(image, pt, pb,
                  Scalar(255, 0, 0),
                  thickness, LINE_8);

        circle(image, pb, 5, Scalar(255, 0, 0), thickness, LINE_8, 1);

        imshow("Output", image);

        waitKey(1);


        image = Mat(500, 500, CV_8UC3,
                    Scalar(255, 255, 255));
    }

    return 0;
}
