// ~/catkin_ws/src/test_pkg/src/num_talker.cpp
#include "ros/ros.h" // /opt/ros/noetic/include/ros/ros.h，提供了 ROS 的基本功能和數據結構。
#include "test_pkg/Num.h" // ~/catkin_ws/devel/include/test_pkg/Num.h
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
		test_pkg::Num A;// 創建類型為test_pkg/Num的變數A。
		A.num = count;// 變數A當中的變數num = count。
		A.bigger_num = count;
		my_publisher.publish(A);// 發佈器(my_publisher)發布話題。my_topic
		
		test_pkg::Num SSS;
		SSS.bigger_num = count;
		SSSPub.publish(SSS);// my/MY/my/MY
		
		std_msgs::String B;
		std::stringstream C;//創建一個 stringstream 物件 C，用於格式化字串。
		C<<"hello "<<count;//將字串 "hello " 和計數值 count 寫入字串流 C。
		B.data=C.str();
		
		if (rate == 4){
			str_pub.publish(B);// str_top
			rate = 0;
		}
		
		ros::spinOnce();
		loop_rate.sleep(); // 暫停一段時間以維持10Hz。
		++count;
		++rate;
	}
	printf("\n");
	return 0;
}
