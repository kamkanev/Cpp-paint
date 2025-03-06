#ifndef P_ELEMENT_H
#define P_ELEMENT_H

#include "utils/brush/brush.h"

class P_Element
{
public:
    P_Element();
    P_Element(Brush b, cv::Point_<int> p);
    virtual void rebuild(cv::Mat drawImage, cv::Mat image) = 0;
protected:
    Brush brush;
    cv::Point_<int> startPoint;
};

#endif // P_ELEMENT_H
