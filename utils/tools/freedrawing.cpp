#include "freedrawing.h"
#include "elements/poly_element.h"

FreeDrawing::FreeDrawing() : ShapeTool() {}

FreeDrawing::FreeDrawing(bool state) : ShapeTool(state) {}

void FreeDrawing::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
    if(drawing){
        line(drawimage, brush.getMouse(), pn, brush.getColor(), brush.getSize(), brush.getLineType());
        points.push_back(brush.getMouse());
        points.push_back(pn);
        brush.updateMouse(pn.x, pn.y);
    }
}
P_Element* FreeDrawing::draw(cv::Mat drawimage, int x, int y){
    //TODO fix pointers problems
    std::vector<cv::Point2i> old(points);
    points = std::vector<cv::Point2i>();
    return new Poly_Element(brush.copySelf(), brush.getMouse(), old);
}

void FreeDrawing::focus(cv::Mat image){
    return;
}
