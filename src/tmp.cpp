#include <ros/ros.h>
#include <geometry_msgs/Pose.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "tmp");

    ros::NodeHandle nh;
    ros::Publisher pose = nh.advertise<geometry_msgs::Pose>("moveto", 1000);

    geometry_msgs::Pose msg;
    msg.position.x = 0.2;
    msg.position.y = 0.2;
    msg.position.z = 0.2;
    msg.orientation.z = 0;
    msg.orientation.z = 0;
    msg.orientation.z = 0;

    pose.publish(msg);

    return 0;
}
