#include "line_element.h"

Line_Element::Line_Element(Brush b, cv::Point_<int> p, cv::Point_<int> pe) : P_Element(b, p) {
    endPoint.x = pe.x;
    endPoint.y = pe.y;
}

void Line_Element::rebuild(cv::Mat drawImage, cv::Mat image){
    line(drawImage, startPoint, endPoint, brush.getColor(), brush.getSize(), brush.getLineType());
}


