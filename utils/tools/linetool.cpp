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
        line(drawimage, brush.getMouse(), pn, brush.getColor(), brush.getSize(), brush.getLineType());
        //brush.updateMouse(pn.x, pn.y);
        return new Line_Element(brush.copySelf(), brush.getMouse(), pn);
    }

    return NULL;
}

void LineTool::focus(cv::Mat image){
    if(drawing && brush.getMouse().x != -1){
        cv::line(image, brush.getMouse(), pn,
                      brush.getColor(),
                      brush.getSize(), brush.getLineType());
    }
}
