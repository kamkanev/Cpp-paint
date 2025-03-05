#ifndef SHAPETOOL_H
#define SHAPETOOL_H

#include "brush.h"

class ShapeTool
{
public:
    ShapeTool();
    ShapeTool(bool state);

    void updateTool(int x, int y);
    virtual void draw(cv::Mat drawimage, int x, int y) = 0;
    virtual void updateDraw(cv::Mat drawimage, int x, int y) = 0;
    virtual void focus(cv::Mat image)= 0;

    //getters
    cv::Point_<int> getNextPoint();
    Brush getBrush();
    bool isDrawing();

    //setters
    void setNextPoint(cv::Point_<int> pn);
    void setNextPoint(int x, int y);
    void setDrawingState(bool state);

    Brush* brushPointer = &brush;

protected:
    Brush brush = Brush();
    cv::Point_<int> pn;
    bool drawing = false;

};

#endif // SHAPETOOL_H
