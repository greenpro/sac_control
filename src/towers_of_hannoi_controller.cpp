// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sac_msgs/Target.h>
//#include <sac_msgs/Path.h>
#include <sac_msgs/HandPos.h>

#define CONTROLLER_NUM (1)
#define PI (3.1459265)

bool enabled = false;
selector *sel;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "towers_of_hannoi_controller");

    ros::NodeHandle nh;

    ros::Publisher targets = nh.advertise<sac_msgs::Target>("/moveto", 1000);
    sac_msgs::Target targetMsg;
    ros::Publisher hand = nh.advertise<sac_msgs::HandPos>("/handDriver", 1000);
    sac_msgs::HandPos handMsg;

    sleep(30);
    while (1)
    {
        ROS_INFO("MOVE INTO PLACE");
        targetMsg.x = 0.400;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = 0;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.064;
        hand.publish(handMsg);

        sleep(20);
        ROS_INFO("MOVE DOWN");

        targetMsg.x = 0.400;
        targetMsg.y = 0.000;
        targetMsg.z = 0.005;
        targetMsg.pitch = 0;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.064;
        hand.publish(handMsg);

        sleep(20);
        ROS_INFO("GRIP");

        targetMsg.x = 0.400;
        targetMsg.y = 0.000;
        targetMsg.z = 0.005;
        targetMsg.pitch = 0;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.030;
        hand.publish(handMsg);

        sleep(20);
        ROS_INFO("LIFT");

        targetMsg.x = 0.400;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = 0;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.030;
        hand.publish(handMsg);

        sleep(20);
        ROS_INFO("DROP");

        targetMsg.x = 0.400;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = 0;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.64;
        hand.publish(handMsg);

        sleep(20);
    }
}
