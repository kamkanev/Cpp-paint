#include "brush.h"

using namespace cv;
using namespace std;

Brush::Brush() {
    this->mouse = Point(-1, -1);
    this->size = 5;
    this->lineType = cv::LINE_8;
    this->color = Scalar(255, 0, 0);
}


void Brush::updateMouse(int x, int y){
    mouse.x = x;
    mouse.y = y;
}

void Brush::setColor(Scalar newColor){
    this->color = newColor;
}

void Brush::setSize(int newSize){
    if(newSize > 0 && newSize < Brush::MAXSIZE){
        this->size = newSize;
    }else{
        throw invalid_argument("new size is is too big or too small. newSize must be > 0 and < MAXSIZW");
    }
}

void Brush::setType(LineTypes newType){
    this->lineType = newType;
}

Scalar Brush::getColor(){
    return color;
}

int Brush::getSize(){
    return size;
}

LineTypes Brush::getLineType(){
    return lineType;
}

Point Brush::getMouse(){
    return mouse;
}
