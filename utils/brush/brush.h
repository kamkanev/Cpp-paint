#ifndef BRUSH_H
#define BRUSH_H

#include "opencv2/imgproc.hpp"
#include<opencv2/core.hpp>

class Brush
{
public:
    //constructors
    Brush();


    //methods
    void updateMouse(int x, int y);
    Brush copySelf();

    //setters
    void setColor(cv::Scalar newColor);
    //void setColor(int r, int b, int g);
    void setSize(int newSize);
    void setType(cv::LineTypes newType);

    //getters
    int getSize();
    cv::Scalar getColor();
    cv::LineTypes getLineType();
    cv::Point getMouse();

    //const and vars
    int MAXSIZE = 100;
    int* sizePointer = &size;
    cv::Scalar* colorPointer = &color;
private:
    cv::Scalar color;
    int size;
    cv::LineTypes lineType;
    cv::Point mouse;
};

#endif // BRUSH_H
