#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv )
{

    Mat img;
    VideoCapture cam(0);

    namedWindow("camera");

    while (true)
    {
        cam.read(img);
        imshow("camera", img);
        waitKey(1);
        
    }
}