// ~/catkin_ws/src/test_pkg/src/hello_name.cpp

// add_executable(hello_eexx src/hello_name.cpp)
// target_link_libraries(hello_eexx ${catkin_LIBRARIES})

// ~/catkin_ws/devel/lib/test_pkg/hello_eexx		hello_eexx is executable file

// rosrun test_pkg hello_eexx

// rosnode list	/hello_node_node

#include "ros/ros.h"

int main(int argc,char*argv[])
{
	ros::init(argc,argv,"hello_node_node"); // hello_node_node is node name, node name can be same.
	ros::NodeHandle handler;
	ros::Rate AAA(1);
	
	while (ros::ok()){
		ROS_INFO("hello world print");
		AAA.sleep();
	}
	return 0;
}
