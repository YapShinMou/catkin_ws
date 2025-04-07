#include "ros/ros.h"
#include "test_pkg/Num.h"
#include "std_msgs/String.h" // /opt/ros/noetic/include/std_msgs/String.h
#include <sstream>

int main(int argc, char **argv){
	ros::init(argc, argv, "num_talker");
	ros::NodeHandle n;
	ros::Publisher my_publisher = n.advertise<test_pkg::Num>("my_topic", 1000);
	ros::Publisher str_pub= n.advertise<std_msgs::String>("str_top", 1000);
	ros::Publisher SSSPub = n.advertise<test_pkg::Num>("my/MY/my/MY", 1000);
	ros::Rate loop_rate(5);
	int count = 0;
	int rate = 0;
	
	while (ros::ok()){
		test_pkg::Num A;
		A.num = count;
		A.bigger_num = count;
		my_publisher.publish(A);
		
		test_pkg::Num SSS;
		SSS.bigger_num = count;
		SSSPub.publish(SSS);
		
		std_msgs::String B;
		std::stringstream C;
		C<<"hello"<<count;
		B.data=C.str();
		
		if (rate == 4){
			str_pub.publish(B);
			rate = 0;
		}
		
		ros::spinOnce();
		loop_rate.sleep();
		++count;
		++rate;
	}
	printf("\n");
	return 0;
}
