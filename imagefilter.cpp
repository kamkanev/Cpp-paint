#include "imagefilter.h"

using namespace cv;

ImageFilter::ImageFilter(String imgPath) {
    src = imread(imgPath);
}

ImageFilter::ImageFilter(Mat image){
    src = image;
}
/** @brief Blurs the image using a specific algorithm
@param type the type of blur you want (0 - 2)
*/
void ImageFilter::blur(int type){
    switch (type) {
    case 0:
        GaussianBlur(src, out, Size(15,15),1);
        break;
    case 1:
        medianBlur(src, out, 9);
        break;
    default:
        bilateralFilter(src, out, 20, 90, 10);
        break;
    }
}

Mat ImageFilter::getOutput(){
    return out;
}

Mat ImageFilter::getSourceImage(){
    return src;
}
