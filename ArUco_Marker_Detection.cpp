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
    cout<<"Please input the number that corresponds to the dictionary containing the Aruco marker you desire."<<endl;
    cout<<"{dictionary: DICT_4X4_50=0, DICT_4X4_100=1, DICT_4X4_250=2,"
            "DICT_4X4_1000=3, DICT_5X5_50=4, DICT_5X5_100=5, DICT_5X5_250=6, DICT_5X5_1000=7, "
            "DICT_6X6_50=8, DICT_6X6_100=9, DICT_6X6_250=10, DICT_6X6_1000=11, DICT_7X7_50=12,"
            "DICT_7X7_100=13, DICT_7X7_250=14, DICT_7X7_1000=15, DICT_ARUCO_ORIGINAL = 16}"<<endl;
    cin>>dictionaryID;
    aruco::Dictionary diction = aruco::getPredefinedDictionary(aruco::PredefinedDictionaryType(dictionaryID));
    aruco::ArucoDetector detector(diction,params);
    VideoCapture inputvideo;
    int camId;
    cout<<"Enter the Camera ID"<<endl;
    cin>>camId;
    inputvideo.open(camId);
    while(inputvideo.grab())
    {
        Mat image,imageCopy;
        inputvideo.retrieve(image);
        //imshow("image",image);
        vector<int>ids;
        vector< vector< Point2f > > corners,rejected;
        detector.detectMarkers(image,corners,ids,rejected);
        image.copyTo(imageCopy);
        if(!ids.empty())
        {
            for(int i=0;i<ids.size();i++)
            {
               cout<<"Number "<<i<<" "<<"ID Number : "<<ids[i]<<" "<<endl;
            }
            aruco::drawDetectedMarkers(imageCopy,corners,ids);
         }
        imshow("ouTPut ImAgE",imageCopy);
        waitKey(10);
      }
    return 0;
}
