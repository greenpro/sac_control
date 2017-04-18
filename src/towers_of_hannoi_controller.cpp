// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sac_msgs/Target.h>
//#include <sac_msgs/Path.h>
#include <sac_msgs/HandPos.h>

namespace towers
{
    // constants
    const char *nodeName = "towers_of_hannoi_controller";
    const int controllerNum = 1;
    const float pi = 3.1415926535898;

    // variables
    bool enabled = true; // change this to false later if this is not the default node.
    selector *sel;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, towers::nodeName);

    ros::NodeHandle nh;

    ros::Publisher targets = nh.advertise<sac_msgs::Target>("/moveto", 1000);
    sac_msgs::Target targetMsg;
    ros::Publisher hand = nh.advertise<sac_msgs::HandPos>("/handDriver", 1000);
    sac_msgs::HandPos handMsg;

    sleep(40);
    while (towers::enabled)
    {
        targetMsg.x = 0.336;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.065;
        hand.publish(handMsg);

        sleep(25);

        targetMsg.x = 0.236;
        targetMsg.y = 0.000;
        targetMsg.z = 0.005;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.065;
        hand.publish(handMsg);

        sleep(25);

        targetMsg.x = 0.236;
        targetMsg.y = 0.000;
        targetMsg.z = 0.005;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.040;
        hand.publish(handMsg);

        sleep(25);

        targetMsg.x = 0.336;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.040;
        hand.publish(handMsg);

        sleep(25);
        //ROS_INFO("MOVE DOWN");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.005;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.064;
        //hand.publish(handMsg);

        //sleep(20);
        //ROS_INFO("GRIP");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.005;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.030;
        //hand.publish(handMsg);

        //sleep(20);
        //ROS_INFO("LIFT");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.100;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.030;
        //hand.publish(handMsg);

        //sleep(20);
        //ROS_INFO("DROP");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.100;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.64;
        //hand.publish(handMsg);

        //sleep(20);
    }
}
