// Include the header file that has declarations for the standard ROS classes
#include "ros/ros.h"
// Include the srv file that we already created
#include "my_custom_srv_msg_pkg/noetic_basics_part_1_srv.h"


// This header is for the C standard general utilities library
// It defines some general purpose functions such as integer arithmetic
#include <cstdlib>
 
int main(int argc, char **argv) {
 
  // Initialize the node and set the name
  ros::init(argc, argv, "adder_client");
   
  // argc is the count of the number of arguments passed in the command line
  // For example, if you're adding two numbers, the three arguments in the 
  // Linux terminal would be the stuff in between []: 
  //   rosrun <package_name> [client_name] [1st_number] [2nd_number]
  // This code below checks that there are three arguments passed in the command
  // line. If there aren't a message is printed to the terminal window.
  if (argc != 3) {
    ROS_INFO("Usage: adder_client A B ");
    return 1;
  }
 
  // Create the main access point for the node
  // This piece of code enables the node to communicate with the ROS system.
  ros::NodeHandle nh;
   
  // Create a client for the service named noetic_basics_part_1/adder
  ros::ServiceClient client = nh.serviceClient<my_custom_srv_msg_pkg::noetic_basics_part_1_srv>("noetic_basics_part_1/adder");
   
  // Create an instance of the srv request data type
  my_custom_srv_msg_pkg::noetic_basics_part_1_srv srv;
   
  // Fill in the two values that will be sent to the Service Server in that exact order
  srv.request.A = atoll(argv[1]);
  srv.request.B = atoll(argv[2]);
   
  // Call the service, and send the data
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service adder_server");
    return 1;
  }
 
  return 0;
}