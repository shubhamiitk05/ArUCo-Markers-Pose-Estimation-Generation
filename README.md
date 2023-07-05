# ArUCo-Markers-Pose-Estimation-Generation
This repository contains all the code you need to generate an ArucoMarker, detect ArucoMarkers in images and videos, and then use the detected Marker to estimate the pose of the object. In addition to this, I have also included the code required to obtain the calibration matrix for your camera.
You can execute these programs directly in your terminal by running the appropraite commands.

## 1. ArUCo Marker Generation
The file `Generate_ArUco_Markers.cpp` contains the code for ArUCo Marker Generation.
You need to specify the type of marker you want to generate(Marker Type and Marker ID).
<img src= Images/ArUcoMarker.png>

## 2. ArUCo Marker Detection
The files `ArUco_Marker_Image_Detection.cpp` contains the code for detecting
ArUCo Markers in images. You need to specify the path to the image and the type of marker you want to detect.Note that this code could be easily modified to perform 
pose estimation on video files.  

The files `ArUco_Marker_Detection.cpp` contains the code for detecting
ArUCo Markers using Camera Feed . You need to specify the camId of the USB Camera you are using and the type of marker you want to detect.

## 3. Calibration
The file `camera_calibaration.cpp` contains the code necessary for calibrating your camera.
Follow the steps mentioned on the Website https://docs.opencv.org/4.x/da/d13/tutorial_aruco_calibration.html.

The file `create_ArUco_Board.cpp` contains the code for generating ArUco Boards.

The parameters for this function will look something like this
"camera_calib.txt" -w=5 -h=7 -l=100 -s=10 -d=10

## 4. Pose Estimation  
The file `ArUco_Marker_Pose_Estimation.cpp` contains the code that performs pose estimation after detecting the 
ArUCo markers. This is done in real-time for each frame obtained from the web-cam feed. You need to specify 
the path to the camera calibration matrix and distortion coefficients obtained from the previous step as well 
as the type for ArUCo marker you want to detect. Note that this code could be easily modified to perform 
pose estimation on images and video files.  

Feel free to reach out to me in case of any issues.  
If you find this repo useful in any way please do star ⭐️ it so that others can reap it's benefits as well.

## References
1. https://docs.opencv.org/4.x/d9/d6d/tutorial_table_of_content_aruco.html
2. https://docs.opencv.org/4.x/da/d13/tutorial_aruco_calibration.html
