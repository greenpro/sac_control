// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sac_msgs/Target.h>
//#include <sac_msgs/Path.h>

#define CONTROLLER_NUM 1

bool enabled = false;
selector *sel;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "towers_of_hannoi_controller");

    ros::NodeHandle nh;

    ros::Publisher targets = nh.advertise<sac_msgs::Target>("/moveto", 1000);
    sac_msgs::Target msg;

    sleep(10);
    while (1)
    {
        msg.x = 0.400;
        msg.y = 0.000;
        msg.z = 0.349;
        targets.publish(msg);

        sleep(3);

        msg.x = 0.000;
        msg.y = 0.400;
        targets.publish(msg);

        sleep(3);
    }
}
