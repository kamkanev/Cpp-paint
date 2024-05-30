#include "imagefilter.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("/home/kamen/git/Cpp-paint/lenna.png", IMREAD_COLOR);
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    ImageFilter blurImg{"/home/kamen/git/Cpp-paint/lenna.png"};
    blurImg.blur(ImageFilter::GAUSSIAN_BLUR);

    String WindowName = "Lenna";

    namedWindow(WindowName);

    imshow(WindowName, image);
    imshow("Output", blurImg.getOutput());

    waitKey(0);
    destroyAllWindows();

    return 0;
}
