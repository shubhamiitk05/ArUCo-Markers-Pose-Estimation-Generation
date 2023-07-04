#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "aruco_samples_utility.hpp"
using namespace std;
using namespace cv;
int main()
{
    float markerLength=0.1;
    string c="/home/yashveer/opencv_build/arucopractice_qt/build/cameraparam.txt";
    aruco::DetectorParameters params=aruco::DetectorParameters();
    aruco::Dictionary diction = aruco::getPredefinedDictionary(aruco::PredefinedDictionaryType(10));
    aruco::ArucoDetector detector(diction,params);
    Mat Cammatrix;
    Mat Distcoeff;
    bool readok=readCameraParameters(c,Cammatrix,Distcoeff);
    if(readok==false)
    {
        cout << "Not Working"<<endl;
    }
    //Set Coordinate System
    Mat objPoints(4, 1, CV_32FC3);
        objPoints.ptr<Vec3f>(0)[0] = Vec3f(-markerLength/2.f, markerLength/2.f, 0);
        objPoints.ptr<Vec3f>(0)[1] = Vec3f(markerLength/2.f, markerLength/2.f, 0);
        objPoints.ptr<Vec3f>(0)[2] = Vec3f(markerLength/2.f, -markerLength/2.f, 0);
        objPoints.ptr<Vec3f>(0)[3] = Vec3f(-markerLength/2.f, -markerLength/2.f, 0);
    VideoCapture inputvideo;
    int camId=0;
    inputvideo.open(camId);

    while(inputvideo.grab())
    {
        Mat image,imageCopy;
        inputvideo.retrieve(image);
        imshow("image",image);
        vector<int>ids;
        vector< vector< Point2f > > corners,rejected;
        detector.detectMarkers(image,corners,ids,rejected);
        size_t nmarker=corners.size();
        vector<Vec3d> rvecs(nmarker);
        vector<Vec3d> tvecs(nmarker);
        if(!ids.empty())
        {
            for(size_t i=0;i<nmarker;i++)
            {
                solvePnP(objPoints,corners.at(i),Cammatrix,Distcoeff,rvecs.at(i),tvecs.at(i));
            }
        }

        image.copyTo(imageCopy);
        if(!ids.empty())
                {

                    for(int i=0;i<ids.size();i++)
                    {
                        cout<<"Number "<<i<<" "<<"ID Number : "<<ids[i]<<" "<<endl;
                    }
                    aruco::drawDetectedMarkers(imageCopy,corners,ids);
                    for(unsigned int i=0;i<ids.size();i++)
                    {
                        drawFrameAxes(imageCopy,Cammatrix,Distcoeff,rvecs[i],tvecs[i],markerLength*1.5f,2);
                    }

                }
        imshow("ouTPut ImAgE",imageCopy);
        for(auto i:tvecs)
        {
            cout<<i[2]<<endl;
        }
        waitKey(10);
    }



        return 0;
}
