#ifndef LINE_ELEMENT_H
#define LINE_ELEMENT_H

#include "p_element.h"

class Line_Element : public P_Element
{
public:
    Line_Element(Brush b, cv::Point_<int> p, cv::Point_<int> pe);
    void rebuild(cv::Mat drawImage, cv::Mat image);
private:
    cv::Point2i endPoint;
};

#endif // LINE_ELEMENT_H
