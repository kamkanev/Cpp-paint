#ifndef CANVAS_H
#define CANVAS_H

#include<opencv2/core.hpp>

class Canvas
{
public:
    Canvas(int weight, int height, cv::Scalar color);

    cv::Mat getImage();
    cv::Mat getDrawImage();
    void update();

private:
    cv::Mat image;
    cv::Mat drawimage;
};

#endif // CANVAS_H
