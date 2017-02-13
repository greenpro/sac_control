#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String::ConstPtr& msg)
{
    // Format and send the data to the usb here.
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "usb");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("usb", 1000, callback);

    ros::spin();

    return 0;
}
