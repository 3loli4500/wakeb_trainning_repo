#include <ros/ros.h>
#include "geometry_msgs/Twist.h" // Motor Commands
#include "sensor_msgs/LaserScan.h" // Laser Data
#include <sstream>
#include <std_msgs/String.h>


//global varibales 
geometry_msgs::Twist velocity_telop;
float msgg=0.0;
std_msgs::String str_msgf;

//callback function related to the subscriber
void callback_teleop(geometry_msgs::Twist::ConstPtr msg){
velocity_telop.linear.x = msg->linear.x;
velocity_telop.linear.y = msg->linear.y;
velocity_telop.linear.z = msg->linear.z;
/////
velocity_telop.angular.x = msg->angular.x;
velocity_telop.angular.y = msg->angular.y;
velocity_telop.angular.z = msg->angular.z;

//ROS_INFO(*msg);
ROS_INFO("number is [%f]",msgg);

}
void callback(sensor_msgs::LaserScan::ConstPtr msg){
msgg = msg->ranges[0];
//ROS_INFO(*msg);
ROS_INFO("number is [%f]",msgg);

}

int main (int argc, char** argv){
   

// ros node - [avoid_obstacles]
ros::init(argc,argv,"avoid_obstacles");
//nodehandler
ros::NodeHandle nh;
//subscribe from topic - [scan]
ros::Subscriber sub = nh.subscribe("scan",10,callback);

ros::Subscriber sub_teleop = nh.subscribe("cmd_vel_telop",10,callback_teleop);

// publish onto topic - [cmd_vel]
ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",10);
//set the publish rate
ros::Rate rate(10);
//while loop to make it not 


 


while(ros::ok){
//order robot to move forward

//todo:assign velocity params
//  velocity.linear.x = ;
//  velocity.linear.y = ;
//  velocity.linear.z = ;
// ///////////////////////////////
// velocity.angular.x;
// velocity.angular.y;
// velocity.angular.z;

//todo: if obsatcle is close: stop the robot, else: dont dont do anything 
if (msgg < 0.5 || msgg < 0.5 !){
velocity_telop.linear.x =0.0;
velocity_telop.linear.y =0.0;
velocity_telop.linear.z =0.0;
///////////////////////////////
velocity_telop.angular.x =0.0;
velocity_telop.angular.y =0.0;
velocity_telop.angular.z =0.0;
    
}
pub.publish(velocity_telop);

//todo: publish ont cmd_vel msg of type geometry_msgs

ros::spinOnce();
rate.sleep();
}

return 0;
}