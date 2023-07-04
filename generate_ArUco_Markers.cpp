#include<opencv2/aruco.hpp>
#include<iostream>
#include"opencv2/highgui.hpp"
#include"aruco_samples_utility.hpp"

using namespace std;
using namespace  cv;
int  main()
{
    int dictionaryID;
    cout<<"Please input the number that corresponds to the dictionary containing the Aruco marker you desire."<<endl;
    cout<<"{dictionary: DICT_4X4_50=0, DICT_4X4_100=1, DICT_4X4_250=2,"
            "DICT_4X4_1000=3, DICT_5X5_50=4, DICT_5X5_100=5, DICT_5X5_250=6, DICT_5X5_1000=7, "
            "DICT_6X6_50=8, DICT_6X6_100=9, DICT_6X6_250=10, DICT_6X6_1000=11, DICT_7X7_50=12,"
            "DICT_7X7_100=13, DICT_7X7_250=14, DICT_7X7_1000=15, DICT_ARUCO_ORIGINAL = 16}"<<endl;
    cin>>dictionaryID;
    int markerID;
    cout<<"Now , Enter the marker ID"<<endl;
    cin>>markerID;
    cv::Mat newmarker;
    aruco::Dictionary dictionary = aruco::getPredefinedDictionary(dictionaryID);
    aruco::generateImageMarker(dictionary,markerID,200,newmarker,1); //Here,200 is the size of the ArUco Marker
    imshow("Generated Marker",newmarker);
    imwrite("/home/yashveer/Downloads/newmarker.jpg", newmarker); //Path where you would want to save your marker for future purposes.
    waitKey(0);
    return 0;
}
