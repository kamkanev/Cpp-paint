#include "rectdrawing.h"
#include "elements/rect_element.h"

RectDrawing::RectDrawing() : ShapeTool() {}

RectDrawing::RectDrawing(bool state) : ShapeTool(state) {}

void RectDrawing::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
}

P_Element* RectDrawing::draw(cv::Mat drawimage, int x, int y){
    if(drawing){
        rectangle(drawimage, brushPointer->getMouse(), pn,
                  brushPointer->getColor(), brushPointer->getSize(), brushPointer->getLineType());
        return new Rect_Element(brushPointer->copySelf(), brushPointer->getMouse(), pn);
    }
    return NULL;
}

void RectDrawing::focus(cv::Mat image){
    if(drawing && brushPointer->getMouse().x != -1){
        cv::rectangle(image, brushPointer->getMouse(), pn,
                      brushPointer->getColor(),
                      brushPointer->getSize(), brushPointer->getLineType());
    }
}
