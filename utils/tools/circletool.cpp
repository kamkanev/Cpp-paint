#include "circletool.h"
#include "elements/circle_element.h"

CircleTool::CircleTool() : ShapeTool() {}

CircleTool::CircleTool(bool state) : ShapeTool(state) {}

void CircleTool::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
    if(drawing){
        r = sqrt(pow(fabs(brushPointer->getMouse().x - pn.x),2) + pow(fabs(brushPointer->getMouse().y - pn.y),2));
    }

}
P_Element* CircleTool::draw(cv::Mat drawimage, int x, int y){
    if(drawing){
        cv::circle(drawimage, brushPointer->getMouse(), r, brushPointer->getColor(), brushPointer->getSize(), brushPointer->getLineType());
        return new Circle_Element(brushPointer->copySelf(), brushPointer->getMouse(), r);
    }

    return NULL;
}

void CircleTool::focus(cv::Mat image){
    if(drawing && brushPointer->getMouse().x != -1){
        cv::circle(image, brushPointer->getMouse(), r,
                 brushPointer->getColor(),
                 brushPointer->getSize(), brushPointer->getLineType());
    }
}
