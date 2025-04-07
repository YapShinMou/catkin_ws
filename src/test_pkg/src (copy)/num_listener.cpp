#include "ros/ros.h"
#include "test_pkg/Num.h"
#include "std_msgs/String.h"
#include <sstream>

void my_Callback(const test_pkg::NumConstPtr& A)
{
	ROS_INFO("I heard: First num = %d, Second num = %d", A->num, A->bigger_num);
}

void CallcallCall(const std_msgs::String::ConstPtr& Bm)
{
	ROS_INFO("%s", Bm->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener"); //It's name is same with listener.cpp
	ros::NodeHandle n;
	ros::Subscriber my_Asub = n.subscribe("my_topic", 1000, my_Callback);
	ros::Subscriber str_Bsub = n.subscribe("str_top", 1000, CallcallCall);
	ros::spin();
	printf("\n");
	return 0;
}
