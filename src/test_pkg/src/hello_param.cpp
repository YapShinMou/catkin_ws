#include "ros/ros.h" // /opt/ros/noetic/include/ros/ros.h
#include <sstream>

int main(int argc,char*argv[])
{
	ros::init(argc,argv,"hello_param_cpp"); //rosnode initialize
	ros::NodeHandle handler;  // create Node Handler - handler
	
	float T;
	std::string SS;
	
	handler.getParam("/print_per", T);
	ros::Rate loop_rate(T);
	
	while (ros::ok()){
		handler.getParam("/print_per", T);
		handler.getParam("test_param_string", SS);
		ROS_INFO("hello_Parameter_cpp %f", T); //Output，hello world
		ROS_INFO("test_param_string: %s", SS.c_str());
		
		loop_rate.sleep();
	}
	return 0;
}
