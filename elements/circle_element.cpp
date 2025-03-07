#include "circle_element.h"

Circle_Element::Circle_Element(Brush b, cv::Point_<int> p, int r) : P_Element(b, p) {
    this->r = r;
}

void Circle_Element::rebuild(cv::Mat drawImage, cv::Mat image){
    circle(drawImage, startPoint, r, brush.getColor(), brush.getSize(), brush.getLineType());
}
