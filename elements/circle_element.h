#ifndef CIRCLE_ELEMENT_H
#define CIRCLE_ELEMENT_H

#include "p_element.h"

class Circle_Element : public P_Element
{
public:
    Circle_Element(Brush b, cv::Point_<int> p, int r);
    void rebuild(cv::Mat drawImage, cv::Mat image);
private:
    int r = 0;
};

#endif // CIRCLE_ELEMENT_H
