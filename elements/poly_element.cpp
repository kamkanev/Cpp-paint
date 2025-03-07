#include "poly_element.h"


Poly_Element::Poly_Element(){}
Poly_Element::Poly_Element(Brush b, cv::Point_<int> p) : P_Element(b, p) {}

void Poly_Element::rebuild(cv::Mat drawImage, cv::Mat image){
    for(int i = 0; i < points.size(); i++){
        if(i+1 < points.size()){
            line(drawImage, points.at(i), points.at(i+1), brush.getColor(), brush.getSize(), brush.getLineType());
        }
    }
}
