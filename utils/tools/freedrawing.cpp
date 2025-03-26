#include "freedrawing.h"
#include "elements/poly_element.h"

FreeDrawing::FreeDrawing() : ShapeTool() {}

FreeDrawing::FreeDrawing(bool state) : ShapeTool(state) {}

void FreeDrawing::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
    if(drawing){
        line(drawimage, brushPointer->getMouse(), pn, brushPointer->getColor(), brushPointer->getSize(), brushPointer->getLineType());
        points.push_back(brushPointer->getMouse());
        points.push_back(pn);
        brushPointer->updateMouse(pn.x, pn.y);
    }
}
P_Element* FreeDrawing::draw(cv::Mat drawimage, int x, int y){
    //TODO fix pointers problems
    std::vector<cv::Point2i> old(points);
    points = std::vector<cv::Point2i>();
    return new Poly_Element(brushPointer->copySelf(), brushPointer->getMouse(), old);
}

void FreeDrawing::focus(cv::Mat image){
    return;
}
