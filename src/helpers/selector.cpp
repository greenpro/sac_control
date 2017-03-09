#include "selector.h"

selector::selector(int nodeIdent, ros::NodeHandle nh) : 
    nodeIdent(nodeIdent), nh(nh)
{
    sub = nh.subscribe("controllerNode", 1000, callback);
}

selector::~selector()
{
}

void selector::callback(std_msgs::Int32 msg)
{
    selNum = msg->data;
}

bool selector::isSelected()
{
    return nodeIdent == selNum;
}
