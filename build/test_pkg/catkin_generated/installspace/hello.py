#!/usr/bin/env python3
from std_msgs.msg import String
import rospy

rospy.init_node('python_hello_node') #python_hello_node is node name
while not rospy.is_shutdown():
	rospy.loginfo('Hello World')
	rospy.sleep(1)
