#include "freedrawing.h"
#include "elements/poly_element.h"

FreeDrawing::FreeDrawing() : ShapeTool() {
    resPointer = Poly_Element(brush.copySelf(), brush.getMouse());
}

FreeDrawing::FreeDrawing(bool state) : ShapeTool(state) {
    resPointer = Poly_Element(brush.copySelf(), brush.getMouse());
}

void FreeDrawing::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
    if(drawing){
        line(drawimage, brush.getMouse(), pn, brush.getColor(), brush.getSize(), brush.getLineType());
        resPointer.points.push_back(brush.getMouse());
        resPointer.points.push_back(pn);
        brush.updateMouse(pn.x, pn.y);
    }
}
P_Element* FreeDrawing::draw(cv::Mat drawimage, int x, int y){
    //TODO fix pointers problems
    P_Element* pe = &resPointer;
    return pe;
}

void FreeDrawing::focus(cv::Mat image){
    return;
}
