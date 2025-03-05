#include "canvas.h"

using namespace cv;

Canvas::Canvas(int weight, int height, Scalar color) {
    drawimage = Mat(weight, height, CV_8UC3,
                    color);
    drawimage.copyTo(image);
}

void Canvas::update(){
    drawimage.copyTo(image);
}

Mat Canvas::getImage(){
    return image;
}

Mat Canvas::getDrawImage(){
    return drawimage;
}
