// 코드 4-14 파일에 데이터 저장하기

#include <opencv2/opencv.hpp>
#include <iostream>
                                        //
//cv::String filename = "mydata.yml";
//cv::String filename = "mydata.json";
cv::String filename = "mydata.xml";
                                        //
int main()
{
    cv::String name = "Jane";
    int age = 10;
    cv::Point pt1(100, 200);
    //std::vector<int> scores = {80, 90, 50};
    std::vector<std::vector<int>> scores = {{80,70}, {60,90}, {40,50}};
    cv::Mat mat1 = (cv::Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

    cv::FileStorage fs(filename, cv::FileStorage::WRITE);
    if (!fs.isOpened()) {
        std::cerr << "File open failed!" << std::endl;
        return -1;
    }

    fs << "name" << name;
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "scores" << scores;
    fs << "data" << mat1;

    fs.release();

    return 0;
}
