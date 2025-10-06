#!/usr/bin/env python3
from std_msgs.msg import String
import rospy

rospy.init_node('hello_param')  #hello_param is node name
period = rospy.get_param("/print_per")  #讀取參數/print_frq，在終端機用rosparam set建立新參數
while not rospy.is_shutdown():
	rospy.loginfo('Hello Parameter')
	rospy.sleep(period)
