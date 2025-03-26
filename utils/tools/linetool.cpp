#include "linetool.h"
#include "elements/line_element.h"

LineTool::LineTool() : ShapeTool() {}

LineTool::LineTool(bool state) : ShapeTool(state) {}

void LineTool::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;

}
P_Element* LineTool::draw(cv::Mat drawimage, int x, int y){
    if(drawing){
        line(drawimage, brushPointer->getMouse(), pn, brushPointer->getColor(), brushPointer->getSize(), brushPointer->getLineType());
        //brushPointer->updateMouse(pn.x, pn.y);
        return new Line_Element(brushPointer->copySelf(), brushPointer->getMouse(), pn);
    }

    return NULL;
}

void LineTool::focus(cv::Mat image){
    if(drawing && brushPointer->getMouse().x != -1){
        cv::line(image, brushPointer->getMouse(), pn,
                      brushPointer->getColor(),
                      brushPointer->getSize(), brushPointer->getLineType());
    }
}
