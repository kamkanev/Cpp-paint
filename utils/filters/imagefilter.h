#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include<opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
/**
@brief A class for image filtering.
*/
class ImageFilter
{
public:
    ImageFilter(cv::String path);
    ImageFilter(cv::Mat src);
    cv::Mat getOutput();
    cv::Mat getSourceImage();
    void blur(int type);

    enum Blur{
        GAUSSIAN_BLUR = 0, MEDIAN_BLUR = 1, BILATERAL_BLUR = 2
    };

private:
    cv::Mat src;
    cv::Mat out;
};

#endif // IMAGEFILTER_H
