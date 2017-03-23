#ifndef SELECTOR_H
#define SELECTOR_H

#include <ros/ros.h>
#include <std_msgs/Int32.h>


class selector
{
    public:
        // Constructor for the selector.
        // This will initialize the selector with the identifier of the node.
//        selector(int nodeIdent, ros::NodeHandle nh);
        selector(int nodeIdentNum, ros::NodeHandle nh) : 
            nh(nh)
        {
            nodeIdent = new int(nodeIdentNum);
            //selNum = new int();
            sub = nh.subscribe("controllerNode", 1000, callback);
        }
                // Destructor for the selector.
        ~selector()
        {
            delete nodeIdent;
            delete selNum;
        }

        // If the node has been selected or not.
        //bool isSelected();
        static bool isSelected()
        {
            return *nodeIdent == *selNum;
        }

    private:
        // The callback to set the selected node.
        //void callback(std_msgs::Int32 sel);
        static void callback(const std_msgs::Int32::ConstPtr& msg)
        {
            *selNum = msg->data;
        }

        static int *nodeIdent;
        static int *selNum;

        ros::NodeHandle nh;
        ros::Subscriber sub;
};

#endif // SELECTOR_H
