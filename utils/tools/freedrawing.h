#ifndef FREEDRAWING_H
#define FREEDRAWING_H

#include "shapetool.h"
#include <vector>

class FreeDrawing : public ShapeTool
{
public:
    FreeDrawing();
    FreeDrawing(bool state);
    P_Element* draw(cv::Mat drawimage, int x, int y);
    void updateDraw(cv::Mat drawimage, int x, int y);
    void focus(cv::Mat image);
private:
    std::vector<cv::Point2i> points;
};

#endif // FREEDRAWING_H
