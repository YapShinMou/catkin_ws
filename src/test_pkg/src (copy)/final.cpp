#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <iostream> // include iostream in order to input stream

// define MoveBaseAction action client
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

// Navigation to Gaol
bool navigateToGoal(MoveBaseClient &ac, double x, double y, double w) {
    move_base_msgs::MoveBaseGoal goal;

    // Define target pose (Map Frame)
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.orientation.w = w;

    ac.sendGoal(goal);

    // action client
    ac.waitForResult();

	if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
		ROS_INFO("Goal reached successfully!");
		ROS_INFO(" ");
		ROS_INFO(" ________________________ ");
		ROS_INFO("|           |            |");
		ROS_INFO("|                 A      |");
		ROS_INFO("|    B      |            |");
		ROS_INFO("|           ============= ");
		ROS_INFO("|           |");
		ROS_INFO("|  _____    |");
		ROS_INFO("|       |   |");
		ROS_INFO("|   C   |    ");
		ROS_INFO("|=======    |");
		ROS_INFO("|           |");
		ROS_INFO("|           |");
		ROS_INFO("|     D     |");
		ROS_INFO("|           |");
		ROS_INFO("|=     ============= ");
		ROS_INFO("|   E   |     F     |");
		ROS_INFO("|                   |");
		ROS_INFO(" =================== ");
		return true;
	}
	else
	{
		ROS_WARN("Failed to reach the goal.");
		ROS_INFO(" ");
		ROS_INFO(" ________________________ ");
		ROS_INFO("|           |            |");
		ROS_INFO("|                 A      |");
		ROS_INFO("|    B      |            |");
		ROS_INFO("|           ============= ");
		ROS_INFO("|           |");
		ROS_INFO("|  _____    |");
		ROS_INFO("|       |   |");
		ROS_INFO("|   C   |    ");
		ROS_INFO("|=======    |");
		ROS_INFO("|           |");
		ROS_INFO("|           |");
		ROS_INFO("|     D     |");
		ROS_INFO("|           |");
		ROS_INFO("|=     ============= ");
		ROS_INFO("|   E   |     F     |");
		ROS_INFO("|                   |");
		ROS_INFO(" =================== ");
		return false;
	}
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "final");

    // Create Action, and client connect to move_base
    MoveBaseClient ac("move_base", true);

    ROS_INFO("Waiting for move_base action server...");
    ac.waitForServer();
    ROS_INFO("Connected to move_base server");
    
    char room;
    size_t i;
    
	// 請同學依照topic 指定四個目標點並將pose進行更改
    std::vector<std::tuple<double, double, double>> goals = {
	    {6.1, -1.2, 1}, // 目標點 1
	    {4.9, 2.7, 1},  // 目標點 2
	    {1.4, 4.2, 1},  // 目標點 3
	    {-2.6, 1, 1},   //  目標點 4
	    {-6.2, 3.4, 1}, //  目標點 5
	    {-6.2, 0.1, 1}  //  目標點 6
    };
    
    //MAP
    ROS_INFO(" ________________________ ");
    ROS_INFO("|           |            |");
    ROS_INFO("|                 A      |");
    ROS_INFO("|    B      |            |");
    ROS_INFO("|           ============= ");
    ROS_INFO("|           |");
    ROS_INFO("|  _____    |");
    ROS_INFO("|       |   |");
    ROS_INFO("|   C   |    ");
    ROS_INFO("|=======    |");
    ROS_INFO("|           |");
    ROS_INFO("|           |");
    ROS_INFO("|     D     |");
    ROS_INFO("|           |");
    ROS_INFO("|=     ============= ");
    ROS_INFO("|   E   |     F     |");
    ROS_INFO("|                   |");
    ROS_INFO(" =================== ");
    
	//main
	while (ros::ok())
	{
    	std::cin >> room;
    	
		if (room == 'a' || room == 'A')
		{
			ROS_INFO("Navigating to room A");
			i = 0;
		}
		else if (room == 'b' || room == 'B')
		{
			ROS_INFO("Navigating to room B");
			i = 1;
		}
		else if (room == 'c' || room == 'C')
		{
			ROS_INFO("Navigating to room C");
			i = 2;
		}
		else if (room == 'd' || room == 'D')
		{
			ROS_INFO("Navigating to room D");
			i = 3;
		}
		else if (room == 'e' || room == 'E')
		{
			ROS_INFO("Navigating to room E");
			i = 4;
		}
		else if (room == 'f' || room == 'F')
		{
			ROS_INFO("Navigating to room F");
			i = 5;
		}
		else
		{
			
			ROS_INFO(" ________________________ ");
    		ROS_INFO("|           |            |");
    		ROS_INFO("|                 A      |");
			ROS_INFO("|    B      |            |");
			ROS_INFO("|           ============= ");
			ROS_INFO("|           |");
			ROS_INFO("|  _____    |");
			ROS_INFO("|       |   |");
			ROS_INFO("|   C   |    ");
			ROS_INFO("|=======    |");
			ROS_INFO("|           |");
			ROS_INFO("|           |");
			ROS_INFO("|     D     |");
			ROS_INFO("|           |");
			ROS_INFO("|=     ============= ");
			ROS_INFO("|   E   |     F     |");
			ROS_INFO("|                   |");
			ROS_INFO(" =================== ");
			ROS_INFO(" ");
			ROS_INFO("Input Error");
		}
		
		double x = std::get<0>(goals[i]);
		double y = std::get<1>(goals[i]);
		double w = std::get<2>(goals[i]);
		if (!navigateToGoal(ac, x, y, w))
		{
			ROS_WARN("Skipping to the next goal...");
		}
		
	}
	
	ROS_INFO("END");
	return 0;
}

