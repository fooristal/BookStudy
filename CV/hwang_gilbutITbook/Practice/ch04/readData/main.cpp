// 코드 4-15 파일로부터 데이터 불러오기

#include <opencv2/opencv.hpp>
#include <iostream>
                                        //
cv::String filename = "mydata.yml";
//cv::String filename = "mydata.json";
//cv::String filename = "mydata.xml";
                                        //
int main()
{
    cv::String name;
    int age;
    cv::Point pt1;
    //std::vector<int> scores;
    std::vector<std::vector<int>> scores;
    cv::Mat mat1;

    cv::FileStorage fs(filename, cv::FileStorage::READ);
    if (!fs.isOpened()) {
        std::cerr << "File open failed!" << std::endl;
        return -1;
    }

    fs["name"] >> name;
    fs["age"] >> age;
    fs["point"] >> pt1;
    fs["scores"] >> scores;
    fs["data"] >> mat1;

    fs.release();

    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "point: " << pt1 << std::endl;
    std::cout << "scores:\n" << cv::Mat(scores.at(0)).t() << std::endl;
    std::cout << "data:\n" << mat1 << std::endl;

    return 0;
}
