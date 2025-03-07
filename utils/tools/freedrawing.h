#ifndef FREEDRAWING_H
#define FREEDRAWING_H

#include "shapetool.h"
#include "elements/poly_element.h"

class FreeDrawing : public ShapeTool
{
public:
    FreeDrawing();
    FreeDrawing(bool state);
    P_Element* draw(cv::Mat drawimage, int x, int y);
    void updateDraw(cv::Mat drawimage, int x, int y);
    void focus(cv::Mat image);
private:
    Poly_Element resPointer;
};

#endif // FREEDRAWING_H
