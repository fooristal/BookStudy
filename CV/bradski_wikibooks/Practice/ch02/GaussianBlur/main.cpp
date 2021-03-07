// Example 2-5. Loading and then smoothing an image before it is  displayed
// on the screen
#include <opencv2/opencv.hpp>

void help(char ** argv)
{
    std::cout << "\n"
              << "2-05: load and smooth an image before displaying \n"
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

    // Load an image specified on the command line.
    cv::Mat image = cv::imread(argv[1], -1);

    // Create some windows to show the input
    // and output images in.
    cv::namedWindow("Example 2-5-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("GaussianBlur", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("blur", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("medianBlur", cv::WINDOW_AUTOSIZE);
    //cv::namedWindow("bilateralFilter", cv::WINDOW_AUTOSIZE);

    // Create a window to show our input image
    cv::imshow("Example 2-5-in", image);

    // Create an image to hold the smoothed output
    cv::Mat out;

    // Do the something
    // (Note: Could use GaussianBlur(), blur(), medianBlur() or
    // bilateralFilter().
    cv::GaussianBlur(image, out, cv::Size(5,5), 3, 3);
    //cv::GaussianBlur(out, out, cv::Size(5,5), 3, 3);

    // Show the smoothed image in the output window
    cv::imshow("GaussianBlur", out);

    // blur()
    cv::blur(image, out, cv::Size(5,5));
    //cv::blur(out, out, cv::Size(5,5));
    cv::imshow("blur", out);

    // medianBlur()
    cv::medianBlur(image, out, 5);
    //cv::medianBlur(out, out, 5);
    cv::imshow("medianBlur", out);

    // bilateralFilter()


    // Wait for the user to hit a key, windows will self destruct
    cv::waitKey(0);

    return 0;
}
