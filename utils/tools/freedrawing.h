#ifndef FREEDRAWING_H
#define FREEDRAWING_H

#include "shapetool.h"

class FreeDrawing : public ShapeTool
{
public:
    FreeDrawing();
    FreeDrawing(bool state);
    void draw(cv::Mat drawimage, int x, int y);
    void updateDraw(cv::Mat drawimage, int x, int y);
    void focus(cv::Mat image);
};

#endif // FREEDRAWING_H
