#include "rectdrawing.h"

RectDrawing::RectDrawing() : ShapeTool() {}

RectDrawing::RectDrawing(bool state) : ShapeTool(state) {}

void RectDrawing::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
}

void RectDrawing::draw(cv::Mat drawimage, int x, int y){
    if(drawing){
        rectangle(drawimage, brush.getMouse(), pn,
                  brush.getColor(), brush.getSize(), brush.getLineType());
    }
}

void RectDrawing::focus(cv::Mat image){
    if(drawing && brush.getMouse().x != -1){
        cv::rectangle(image, brush.getMouse(), pn,
                      brush.getColor(),
                      brush.getSize(), brush.getLineType());
    }
}
