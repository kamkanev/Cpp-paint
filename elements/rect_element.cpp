#include "rect_element.h"

Rect_Element::Rect_Element(Brush b, cv::Point_<int> p, cv::Point_<int> pe) : P_Element(b, p) {
    endPoint.x = pe.x;
    endPoint.y = pe.y;
}

void Rect_Element::rebuild(cv::Mat drawImage, cv::Mat image){
    rectangle(drawImage, startPoint, endPoint, brush.getColor(), brush.getSize(), brush.getLineType());
}
