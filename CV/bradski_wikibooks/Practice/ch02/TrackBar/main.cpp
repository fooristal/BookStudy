// Example 2-4. Adding a trackbar slider to the basic viewer window for moving around
// within the video file

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
                                        //
int g_slider_position = 0;
int g_run = 1, g_dontset = 0;           // start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *)
{
    g_cap.set(CV_CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset) g_run = 1;
    g_dontset = 0;
    //std::cout << "in onTrackbarSlide()\n" << std::endl;
}
#if 1
void help(char ** argv)
{
    std::cout << "\n"
              << "2-04: Adding a trackbar to a basic viewer "
              << "for moving w/in the video file \n"
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

    cv::namedWindow("Example 2-4", cv::WINDOW_AUTOSIZE);
    g_cap.open(std::string(argv[1]));
    int frames = (int)g_cap.get(CV_CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int tmph = (int)g_cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "Video has " << frames << " frames of dimensions("
              << tmpw << ", " << tmph << ")." << std::endl;

    cv::createTrackbar("Position", "Example 2-4", &g_slider_position,
                       frames, onTrackbarSlide);
    cv::Mat frame;
    for (;;) {
        if (g_run != 0) {
            g_cap >> frame;
            if (frame.empty()) break;

            int current_pos = (int)g_cap.get(CV_CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            cv::setTrackbarPos("Position", "Example 2-4", current_pos);
            cv::imshow("Example 2-4", frame);
            g_run -= 1;
        }
                                        //
        char c = (char)cv::waitKey(10);
        if (c == 's') {                 // single step
            g_run = 1;
            std::cout << "Single step, run = " << g_run << std::endl;
        }

        if (c == 'r') {                 // run mode
            g_run = -1;
            std::cout << "Run mode, run = " << g_run << std::endl;
        }

        if (c == 27) break;
    }
                                        //
    return 0;
}
#else
int main()
{
    cv::namedWindow("Example 2-4", cv::WINDOW_AUTOSIZE);
    g_cap.open(std::string("F:/98_BookStudy/CV/bradski_wikibooks/Data/test.avi"));
    int frames = (int)g_cap.get(CV_CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int tmph = (int)g_cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "Video has " << frames << " frames of dimensions("
              << tmpw << ", " << tmph << ")." << std::endl;

    cv::createTrackbar("Position", "Example 2-4", &g_slider_position,
                       frames, onTrackbarSlide);
    cv::Mat frame;
    for (;;) {
        if (g_run != 0) {
            g_cap >> frame;
            if (frame.empty()) break;

            int current_pos = (int)g_cap.get(CV_CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            cv::setTrackbarPos("Position", "Example 2-4", current_pos);
            cv::imshow("Example 2-4", frame);
            g_run -= 1;
        }
                                        //
        char c = (char)cv::waitKey(10);
        if (c == 's') {                 // single step
            g_run = 1;
            std::cout << "Single step, run = " << g_run << std::endl;
        }

        if (c == 'r') {                 // run mode
            g_run = -1;
            std::cout << "Run mode, run = " << g_run << std::endl;
        }

        if (c == 27) break;
    }
                                        //
    return 0;
}

#endif
