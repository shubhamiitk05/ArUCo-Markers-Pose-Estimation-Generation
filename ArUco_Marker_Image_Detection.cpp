#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "aruco_samples_utility.hpp"

using namespace std;
using namespace cv;

int main()
{
        aruco::DetectorParameters params=aruco::DetectorParameters();
        int dictionaryID;
        cout<<"Please input the number that corresponds to the dictionary containing the Aruco marker which you want to detect."<<endl;
        cout<<"{dictionary: DICT_4X4_50=0, DICT_4X4_100=1, DICT_4X4_250=2,"
                "DICT_4X4_1000=3, DICT_5X5_50=4, DICT_5X5_100=5, DICT_5X5_250=6, DICT_5X5_1000=7, "
                "DICT_6X6_50=8, DICT_6X6_100=9, DICT_6X6_250=10, DICT_6X6_1000=11, DICT_7X7_50=12,"
                "DICT_7X7_100=13, DICT_7X7_250=14, DICT_7X7_1000=15, DICT_ARUCO_ORIGINAL = 16}"<<endl;
        cin>>dictionaryID;
        aruco::Dictionary diction = aruco::getPredefinedDictionary(aruco::PredefinedDictionaryType(dictionaryID));
        aruco::ArucoDetector detector(diction,params);
        Mat inputimage;
        inputimage=imread("/home/yashveer/Downloads/image(1).png"); //Location of the image
        vector<int>ids;
        Mat image_copy;
        vector< vector< Point2f > > corners,rejected;
        detector.detectMarkers(inputimage,corners,ids,rejected);
        image_copy=inputimage.clone();
        cout<<"Number of IDs detected = "<<ids.size()<<endl;
        if(!ids.empty())
        {

            for(int i=0;i<ids.size();i++)
            {
                cout<<"Number "<<i<<" "<<ids[i]<<" "<<endl;
            }
            aruco::drawDetectedMarkers(image_copy,corners,ids);
            imshow("Output Image",image_copy);
            waitKey(0);
        }
        return 0;
}
