// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <shape_msgs/SolidPrimitive.h>
#include <sac_msgs/Target.h>
#include <sac_msgs/Path.h>
#include <sac_msgs/HandPos.h>

namespace towers
{
    // constants
    const char *nodeName = "custom_controller";
    const int controllerNum = 2;
    const float pi = 3.1415926535898;

    // variables
    bool enabled = true; // change this to false later if this is not the default node.
    selector *sel;

    // publishers
    ros::Publisher targets;
    ros::Publisher hand;
}

void move(float x, float y, float z, 
	  float roll, float pitch, float hand)
{
    // Arm movement
    sac_msgs::Target targetMsg;
    
    targetMsg.x = x;
    targetMsg.y = y;
    targetMsg.z = z;
    targetMsg.pitch = pitch;
    targetMsg.roll = roll;
    towers::targets.publish(targetMsg);
    
    // Hand movement
    sac_msgs::HandPos handMsg;
    
    handMsg.width = hand;
    towers::hand.publish(handMsg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, towers::nodeName);

    ros::NodeHandle nh;

    towers::targets = nh.advertise<sac_msgs::Target>("/moveto", 1000);
    towers::hand = nh.advertise<sac_msgs::HandPos>("/handDriver", 1000);

    while (towers::enabled)
    {
        // TODO :: Enter custom control code here.
        // lift into place
        move(0.336000, 0.000000, 0.200000, 
             0.000000, towers::pi / 2, 0.065);
            sleep(30);
    }
}
