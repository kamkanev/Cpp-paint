#include "p_element.h"

P_Element::P_Element() {
    brush = Brush();
    startPoint = cv::Point_<int>(-1,-1);
}

P_Element::P_Element(Brush b, cv::Point_<int> p) {
    brush = b.copySelf();
    startPoint = cv::Point_<int>(p.x, p.y);
}
