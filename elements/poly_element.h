#ifndef POLY_ELEMENT_H
#define POLY_ELEMENT_H

#include "p_element.h"
#include <vector>

class Poly_Element : public P_Element
{
public:
    Poly_Element();
    Poly_Element(Brush b, cv::Point_<int> p);
    void rebuild(cv::Mat drawImage, cv::Mat image);
    std::vector<cv::Point2i> points;
};

#endif // POLY_ELEMENT_H
