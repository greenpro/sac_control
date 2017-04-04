// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sac_msgs/Target.h>
//#include <sac_msgs/Path.h>

#define CONTROLLER_NUM (1)
#define PI (3.1459265)

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
        msg.x = 0.300;
        msg.y = -0.040;
        msg.z = 0.000;
        msg.pitch = PI / 2;
        msg.roll = 0;
        targets.publish(msg);

        sleep(5);

        msg.x = 0.300;
        msg.y = 0.000;
        msg.z = 0.500;
        msg.pitch = 0;
        msg.roll = 0;
        targets.publish(msg);

        sleep(5);

        msg.x = 0.373;
        msg.y = 0.000;
        msg.z = 0.570;
        msg.pitch = 0;
        msg.roll = 0;
        targets.publish(msg);

        sleep(5);
    }
}
