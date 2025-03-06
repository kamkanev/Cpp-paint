#include "circletool.h"

CircleTool::CircleTool() : ShapeTool() {}

CircleTool::CircleTool(bool state) : ShapeTool(state) {}

void CircleTool::updateDraw(cv::Mat drawimage, int x, int y){
    pn.x = x;
    pn.y = y;
    if(drawing){
        r = sqrt(pow(fabs(brush.getMouse().x - pn.x),2) + pow(fabs(brush.getMouse().y - pn.y),2));
    }

}
void CircleTool::draw(cv::Mat drawimage, int x, int y){
    if(drawing){
        cv::circle(drawimage, brush.getMouse(), r, brush.getColor(), brush.getSize(), brush.getLineType());
        r = 0;
    }
}

void CircleTool::focus(cv::Mat image){
    if(drawing && brush.getMouse().x != -1){
        cv::circle(image, brush.getMouse(), r,
                 brush.getColor(),
                 brush.getSize(), brush.getLineType());
    }
}
