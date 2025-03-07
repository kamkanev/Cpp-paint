#ifndef CIRCLETOOL_H
#define CIRCLETOOL_H

#include "shapetool.h"

class CircleTool : public ShapeTool
{
public:
    CircleTool();
    CircleTool(bool state);
    P_Element* draw(cv::Mat drawimage, int x, int y);
    void updateDraw(cv::Mat drawimage, int x, int y);
    void focus(cv::Mat image);
protected:
    int r = 0;
};

#endif // CIRCLETOOL_H
