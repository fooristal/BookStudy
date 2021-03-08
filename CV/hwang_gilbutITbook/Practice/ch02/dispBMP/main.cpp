#include <iostream>

#include <opencv2/opencv.hpp>

                                        //


int main()
{
    std::cout << "Hello OpenCV " << CV_VERSION << std::endl;

    cv::Mat img;
    img = cv::imread("F:/98_BookStudy/CV/hwang_gilbutITbook/Data/images/lenna.bmp");

    if (img.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return -1;
    }

    cv::namedWindow("image");
    cv::imshow("image", img);

    cv::waitKey();

    return 0;
}
