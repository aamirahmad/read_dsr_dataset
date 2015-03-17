#include "read_dsr_dataset.h"

////////////////////////// METHOD DEFINITIONS OF THE SELFROBOT CLASS //////////////////////

void SelfRobot::selfOdometryCallback(const nav_msgs::Odometry::ConstPtr& odometry)
{
  
  uint seq = odometry->header.seq;
  Time curTime = odometry->header.stamp;
  
  ROS_INFO(" got odometry from mbot at time %d\n", odometry->header.stamp.sec);  

}


void SelfRobot::rgbImageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  // Two lines below just to see if you are reading the rgb images correctly. Extend this function as you like to implememnt vision-based perception algorithm
  cv::imshow("RGB_view", cv_bridge::toCvShare(msg, "bgr8")->image);
  cvWaitKey(30);
}


void SelfRobot::depthImageCallBack(const sensor_msgs::Image::ConstPtr& msg)
{
  // Two lines below just to see if you are reading the depth images correctly. Extend this function as you like to implememnt vision-based perception algorithm  
  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_32FC1);
  cv::imshow("Depth_view", cv_ptr->image);
  cv::waitKey(30);
  
}


int main (int argc, char* argv[])
{
  ros::init(argc, argv, "read_dsr_dataset");

  ROS_INFO("Simple trmplates to implement your own perception algorithm using the DSR dataset");

  ReadRobotMessages node;

  spin();
  return 0;
}




























