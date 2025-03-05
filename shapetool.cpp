#include "shapetool.h"

ShapeTool::ShapeTool() {
    pn = cv::Point_<int>(0, 0);
}

ShapeTool::ShapeTool(bool  state) {
    pn = cv::Point_<int>(0, 0);
    drawing = state;
}

void ShapeTool::updateTool(int x, int y){
    brush.updateMouse(x, y);
    pn.x = x;
    pn.y = y;
}

cv::Point_<int> ShapeTool::getNextPoint(){
    return pn;
}

Brush ShapeTool::getBrush(){
    return brush;
}

bool ShapeTool::isDrawing(){
    return drawing;
}

void ShapeTool::setNextPoint(cv::Point_<int> point){
    pn.x = point.x;
    pn.y = point.y;
}

void ShapeTool::setNextPoint(int x, int y){
    pn.x = x;
    pn.y = y;
}

void ShapeTool::setDrawingState(bool state){
    drawing = state;
}


