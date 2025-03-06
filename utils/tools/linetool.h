#ifndef LINETOOL_H
#define LINETOOL_H

#include "shapetool.h"

class LineTool : public ShapeTool
{
public:
    LineTool();
    LineTool(bool state);
    void draw(cv::Mat drawimage, int x, int y);
    void updateDraw(cv::Mat drawimage, int x, int y);
    void focus(cv::Mat image);
};

#endif // LINETOOL_H
