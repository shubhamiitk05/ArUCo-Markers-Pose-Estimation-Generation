# ArUCo-Markers-Pose-Estimation-Generation
This repository contains all the code you need to generate an ArucoMarker, detect ArucoMarkers in images and videos, and then use the detected Marker to estimate the pose of the object. In addition to this, I have also included the code required to obtain the calibration matrix for your camera.

## 1. ArUCo Marker Generation
The file `Generate_ArUco_Markers.cpp` contains the code for ArUCo Marker Generation.
You need to specify the type of marker you want to generate.

## 2. ArUCo Marker Detection
The files `ArUco_Marker_Detection.cpp` contains the code for detecting
ArUCo Markers in videos . You need to specify the camId of the USB Camera you are using and the type of marker you want to detect.Note that this code could be easily modified to perform 
pose estimation on images and video files.  



## 3. Pose Estimation  
The file `ArUco_Marker_Pose_Estimation.cpp` contains the code that performs pose estimation after detecting the 
ArUCo markers. This is done in real-time for each frame obtained from the web-cam feed. You need to specify 
the path to the camera calibration matrix and distortion coefficients obtained from the previous step as well 
as the type for ArUCo marker you want to detect. Note that this code could be easily modified to perform 
pose estimation on images and video files.  

Feel free to reach out to me in case of any issues.  
If you find this repo useful in any way please do star ⭐️ it so that others can reap it's benefits as well.

Happy Learning! Keep chasing your dreams!
