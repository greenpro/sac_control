// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include <helpers/config.h>
#include <ros/ros.h>

#define CONTROLLER_NUM 1

bool enabled = false;

void callback(const std_msgs::Int32::ConstPtr& msg)
{
    if (msg->data == CONTROLLER_NUM)
        enabled = true;
    else
        enabled = false;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "custom_controller");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("controllerMode", 1000, callback);

    //float x, y, z, theta, time
    coordinates = nh.advertise<geometry_msgs

    while (1)
    {
        if (enabled)
        {
            
        }
    }
}
