#!/usr/bin/env python

import rospy
from std_msgs.msg import String
import tf.transformations
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

def callback(data):
    #rospy.loginfo("Laser data received!" % data)
    print "Laser data received"

def talker():
    pub = rospy.Publisher('robot0/cmd_vel', Twist, queue_size=10)
    sub = rospy.Subscriber('robot0/laser_0', LaserScan, callback)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        #hello_str = "hello world %s" % rospy.get_time()
        #rospy.loginfo(hello_str)
        t = Twist()
        t.angular.x = 90
        t.linear.x = 10
        pub.publish(t)
        rate.sleep()

if __name__ == '__main__':
    try:
        print "test"
        talker()
        
    except rospy.ROSInterruptException:
        pass
