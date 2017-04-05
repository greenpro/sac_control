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

    sleep(10);
    while (1)
    {
        targetMsg.x = 0.300;
        targetMsg.y = -0.040;
        targetMsg.z = 0.000;
        targetMsg.pitch = PI / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.000;
        hand.publish(handMsg);

        sleep(5);

        targetMsg.x = 0.400;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = 0;
        targetMsg.roll = PI / 2;
        targets.publish(targetMsg);
        
        handMsg.width = 0.065;
        hand.publish(handMsg);

        sleep(5);

        targetMsg.x = 0.387;
        targetMsg.y = 0.000;
        targetMsg.z = 0.570;
        targetMsg.pitch = 0;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.032;
        hand.publish(handMsg);

        sleep(5);

        targetMsg.x = 0.387;
        targetMsg.y = 0.000;
        targetMsg.z = 0.570;
        targetMsg.pitch = 0;
        targetMsg.roll = PI / 2;
        targets.publish(targetMsg);
        
        handMsg.width = 0.000;
        hand.publish(handMsg);

        sleep(5);

        targetMsg.x = 0.387;
        targetMsg.y = 0.000;
        targetMsg.z = 0.570;
        targetMsg.pitch = 0;
        targetMsg.roll = -PI / 2;
        targets.publish(targetMsg);
        
        handMsg.width = 0.64;
        hand.publish(handMsg);

        sleep(5);
    }
}
