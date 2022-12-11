#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main()
{
    /*these strings are an example. The content of these strings will depend on the application
    and the format we want to convert to.

    Here is shown a UDP source. String 5 won't change.
    
    Concatenation of strings allows us to have a bit more of modulability.*/

    string p_1 = "udpsrc port=5000 ";
    string p_2 = "! application/x-rtp,media=video,payload=26,clock-rate=90000,encoding-name=JPEG,framerate=30/1 ";
    string p_3 = "! rtpjpegdepay ! jpegdec ";
    string p_4 = "! videoconvert ";
    string p_5 = "! appsink";
    string pipeline = p_1 + p_2 + p_3 + p_4 + p_5;
	VideoCapture cap(pipeline, CAP_GSTREAMER);
    
	if (!cap.isOpened()) {
        cerr <<"VideoCapture not opened"<<endl;
        exit(-1);
    }
    
    while (true) {

        Mat frame;

        cap.read(frame);

        imshow("receiver", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}