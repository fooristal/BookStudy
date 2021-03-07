// Example 2-3. A simple OpenCV program for playing a video file from disk

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void help(char ** argv)
{
    std::cout << "\n"
              << "2-03: play video from disk \n"
              << argv[0] << " <path/video>\n"
              << "For example:\n"
              << argv[0] << " ../tree.avi\n"
              << std::endl;
}

int main(int argc, char ** argv)
{
    if (argc != 2) {
        help(argv);
        return 0;
    }

    cv::namedWindow("Example 2-3", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));
    std::cout << "Opened file: " << argv[1] << std::endl;
    cv::Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty()) break;       // Ran out of film
        cv::imshow("Example 2-3", frame);
        if ((char)cv::waitKey(33) >= 0 ) break;
    }
                                        //
    return 0;
}
