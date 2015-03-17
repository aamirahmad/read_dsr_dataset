#include <cstdio>
#include <iostream>
#include <string>


#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>


///TODO These hard coded values must go out of this place. Preferably as the arguments of the main function and therefore in the launch file.


using namespace ros;
using namespace std;
using namespace cv;

class SelfRobot
{
  NodeHandle *nh;
  //One subscriber per sensor in the robot
  Subscriber subOdom_;
  image_transport::Subscriber subRGBIm_;
  image_transport::Subscriber subDepthIm_;
  
  public:
    SelfRobot(NodeHandle *nh)
    {
      
      image_transport::ImageTransport im(*nh);
      
      subOdom_ = nh->subscribe<nav_msgs::Odometry>("/mbot06/odom", 10, boost::bind(&SelfRobot::selfOdometryCallback,this, _1));
      
      subRGBIm_ = im.subscribe("/mbot06/camera/rgb/image_raw", 10, &SelfRobot::rgbImageCallback, this);
      
      subDepthIm_ = im.subscribe("/mbot06/camera/depth_registered/image_raw", 10, &SelfRobot::depthImageCallBack, this);
      
      ROS_INFO(" constructing SelfRobot <<object>> and called sensor subscribers for mbot06");
      
    }
    
    /// Use this method to implement perception algorithms
    void selfOdometryCallback(const nav_msgs::Odometry::ConstPtr&);
    
    /// Use this method to implement perception algorithms
    void rgbImageCallback(const sensor_msgs::Image::ConstPtr&);
     
    /// Use this method to implement perception algorithms
    void depthImageCallBack(const sensor_msgs::Image::ConstPtr&);
    
};


class ReadRobotMessages
{
  NodeHandle nh_;
  Rate loop_rate_;
  
  SelfRobot* robot_;

  public:
    ReadRobotMessages(): loop_rate_(30)
    { 
      robot_ = new SelfRobot(&nh_);     
    }    
};






































