#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;

Scalar redLow1 = Scalar(0, 70, 50);
Scalar redHigh1 = Scalar(10, 255, 255);
Scalar redLow2 = Scalar(170, 70, 50);
Scalar redHigh2 = Scalar(180, 255, 255);


int main(int argc, char** argv )
{

    VideoCapture video("/home/karol/Aksantara/THT_Aksantara2024/RSC_THT_1/src/Red Dot.mp4");

    while (video.isOpened())
    {
        Mat frame;
        bool isSuccess = video.read(frame);

        if (isSuccess == true)
        {
            Mat background;
            frame.copyTo(background);

            cvtColor(frame, frame, COLOR_BGR2HSV);

            Mat mask1, mask2;
            inRange(frame, redLow1, redHigh1, mask1);
            inRange(frame, redLow2, redHigh2, mask2);

            Mat mask = mask1 | mask2;

            std::vector < std::vector < Point>> contours;
            findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
            // drawContours(background, contours, -1, Scalar(0, 255, 0), 3);
            for (size_t i = 0; i < contours.size(); i++)
            {
                Rect boundRect = boundingRect(contours[i]);
                if (boundRect.area() > 100 && (boundRect.width < 500 || boundRect.height < 500))
                {
                    rectangle(background, boundRect.tl(), boundRect.br(), Scalar(255, 0, 0), 3);
                }
                
            }
            

            imshow("contours", background);
            // imshow("red", mask);
        }
 


        if (isSuccess == false)
        {
            std::cout << "Video camera is disconnected" << std::endl;
            break;
        }        
        int key = waitKey(20);
        if (key == 'q')
        {
            std::cout << "q key is pressed by the user. Stopping the video" << std::endl;
            break;
        }
    }

    video.release();
    destroyAllWindows();

}