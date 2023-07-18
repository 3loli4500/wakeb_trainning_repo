#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <sstream>

//global varibales 
int intmsg;
std_msgs::String smsg;
  
  
//callback function related to the subscriber
void callback(const std_msgs::Int32::ConstPtr& msg){
ROS_INFO("number is [%d]",msg->data);
intmsg = msg->data;
}
//int msgg=0;


int main (int argc, char** argv){
// ros node - [int_to_string] 
ros::init(argc,argv,"int_to_string");
//nodehandler
ros::NodeHandle nh;
//subscribe from topic - [int_msg]
ros::Subscriber sub = nh.subscribe("int_msg",10,callback);
// publish onto topic - [string_msg]
ros::Publisher pub = nh.advertise<std_msgs::String>("string_msg",10);
//set the publish rate
ros::Rate rate(1);
//while loop to make it not stop
while(ros::ok){
//intmsgg = int_msg.data;
smsg.data = "Your number is: " + std::to_string(intmsg);
pub.publish(smsg);
ros::spinOnce();
rate.sleep();
}

return 0;
}