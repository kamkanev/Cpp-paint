#include "freedrawing.h"

FreeDrawing::FreeDrawing() : ShapeTool() {}

FreeDrawing::FreeDrawing(bool state) : ShapeTool(state) {}

void FreeDrawing::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
    if(drawing){
        line(drawimage, brush.getMouse(), pn, brush.getColor(), brush.getSize(), brush.getLineType());
        brush.updateMouse(pn.x, pn.y);
    }
}
void FreeDrawing::draw(cv::Mat drawimage, int x, int y){
    return;
}

void FreeDrawing::focus(cv::Mat image){
    return;
}
