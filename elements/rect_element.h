#ifndef RECT_ELEMENT_H
#define RECT_ELEMENT_H

#include "p_element.h"

class Rect_Element : public P_Element
{
public:
    Rect_Element(Brush b, cv::Point_<int> p, cv::Point_<int> pe);
    void rebuild(cv::Mat drawImage, cv::Mat image);
private:
    cv::Point2i endPoint;
};

#endif // RECT_ELEMENT_H
