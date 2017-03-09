#ifndef SELECTOR_H
#define SELECTOR_H

#include <ros/ros.h>
#include <std_msgs/Int32.h>

class selector
{
    public:
        // Constructor for the selector.
        // This will initialize the selector with the identifier of the node.
        selector(int nodeIdent, ros::NodeHandle nh);

        // Destructor for the selector.
        ~selector();

        // If the node has been selected or not.
        bool isSelected();

    private:
        // The callback to set the selected node.
        void callback(std_msgs::Int32 sel);

        int nodeIdent;
        int selNum;

        ros::NodeHandle nh;
        ros::Subscriber sub;
};

#endif // SELECTOR_H
