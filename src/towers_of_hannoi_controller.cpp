// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sac_msgs/Target.h>

#define CONTROLLER_NUM 1

bool enabled = false;
selector *sel;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "custom_controller");

    ros::NodeHandle nh;
//    ros::Subscriber sub = nh.subscribe("controllerMode", 1000, callback);

    //float x, y, z, theta, time
    ros::Publisher coordinates = nh.advertise<geometry_msgs::Twist>("moveto", 1000);

    //sel = new selector(0, nh);

    //while (1)
    //{
    //    if (sel->isSelected())
    //    {
    //        
    //    }
    //}
}
