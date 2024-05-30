#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("/home/kamen/Genshin-Impact-Raiden-Shogun-thumb.png");
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    String WindowName = "Raiden EI";

    namedWindow(WindowName);
    imshow(WindowName, image);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
