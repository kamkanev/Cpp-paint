#ifndef RECTDRAWING_H
#define RECTDRAWING_H

#include "shapetool.h"

class RectDrawing : public ShapeTool
{
public:
    RectDrawing();
    RectDrawing(bool state);

    void draw(cv::Mat drawimage, int x, int y);
    void updateDraw(cv::Mat drawimage, int x, int y);
    void focus(cv::Mat image);
};

#endif // RECTDRAWING_H
