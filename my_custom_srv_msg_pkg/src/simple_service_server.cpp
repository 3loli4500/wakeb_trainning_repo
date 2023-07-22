// Include the header file that has declarations for the standard ROS classes
#include "ros/ros.h"
// Include the srv file that we already created
#include "my_custom_srv_msg_pkg/noetic_basics_part_1_srv.h"
 
// Add two numbers and output the sum
bool add(my_custom_srv_msg_pkg::noetic_basics_part_1_srv::Request  &req,
         my_custom_srv_msg_pkg::noetic_basics_part_1_srv::Response &res) {
//assign sum to be response and A,B to be request
  res.sum = req.A + req.B;

  ROS_INFO("Request: A=%d, B=%d", (int)req.A, (int)req.B);
  ROS_INFO("Response: [%d]", (int)res.sum);
  return true;
}
 
// Main ROS method
int main(int argc, char **argv) {
     
  // Initialize the node and set the name
  ros::init(argc, argv, "adder_server");
   
  // Create the main access point for the node
  // This piece of code enables the node to communicate with the ROS system.
  ros::NodeHandle nh;
 
  // Create the service and advertise it to the ROS computational network
  ros::ServiceServer service = nh.advertiseService("noetic_basics_part_1/adder", add);
   
  // Print message to terminal window
  ROS_INFO("adder_server has started");
   
  // Keep processing information over and over again
  ros::spin();
 
  // Program completed successfully
  return 0;
}