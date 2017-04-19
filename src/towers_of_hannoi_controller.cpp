// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <shape_msgs/SolidPrimitive.h>
#include <sac_msgs/Target.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
//#include <sac_msgs/Path.h>
#include <sac_msgs/HandPos.h>

namespace towers
{
    // constants
    const char *nodeName = "towers_of_hannoi_controller";
    const int controllerNum = 1;
    const float pi = 3.1415926535898;
    const char *planningGroup = "arm";

    // variables
    bool enabled = true; // change this to false later if this is not the default node.
    selector *sel;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, towers::nodeName);

    ros::NodeHandle nh;
    ROS_INFO("-------------------------started");

    ros::Publisher targets = nh.advertise<sac_msgs::Target>("/moveto", 1000);
    sac_msgs::Target targetMsg;
    ros::Publisher hand = nh.advertise<sac_msgs::HandPos>("/handDriver", 1000);
    sac_msgs::HandPos handMsg;
    ROS_INFO("-------------------------publishers");

    sleep(40);
    ROS_INFO("-------------------------sleep finish");
    // planning scene
    moveit::planning_interface::PlanningSceneInterface planningSceneInterface;
    ROS_INFO("-------------------------planning scene");
    // planning group
    moveit::planning_interface::MoveGroupInterface moveGroup(towers::planningGroup);
    ROS_INFO("-------------------------planning group");
    // collision object
    moveit_msgs::CollisionObject collisionObject;
    collisionObject.header.frame_id = moveGroup.getPlanningFrame();
    collisionObject.id = "towerBase";
    ROS_INFO("-------------------------collision");
    // define the object
    shape_msgs::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions.resize(3);
    primitive.dimensions[0] = 0.4;
    primitive.dimensions[1] = 0.4;
    primitive.dimensions[2] = 0.4;
    ROS_INFO("-------------------------object definition");
    // define the object pos
    geometry_msgs::Pose boxPose;
    boxPose.orientation.w = 1.0;
    boxPose.position.x = 0.6;
    boxPose.position.y = -0.4;
    boxPose.position.z = 1.2;
    ROS_INFO("-------------------------object pose");

    collisionObject.primitives.push_back(primitive);
    collisionObject.primitive_poses.push_back(boxPose);
    collisionObject.operation = collisionObject.ADD;

    std::vector<moveit_msgs::CollisionObject> collisionObjects;
    collisionObjects.push_back(collisionObject);
    ROS_INFO("-------------------------collision object");

    // Add the objects to the world
    planningSceneInterface.addCollisionObjects(collisionObjects);
    ROS_INFO("-------------------------added");

    while (towers::enabled)
    {
        targetMsg.x = 0.336;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.065;
        hand.publish(handMsg);

        sleep(25);

        targetMsg.x = 0.236;
        targetMsg.y = 0.000;
        targetMsg.z = 0.005;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.065;
        hand.publish(handMsg);

        sleep(25);

        targetMsg.x = 0.236;
        targetMsg.y = 0.000;
        targetMsg.z = 0.005;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.040;
        hand.publish(handMsg);

        sleep(25);

        targetMsg.x = 0.336;
        targetMsg.y = 0.000;
        targetMsg.z = 0.100;
        targetMsg.pitch = towers::pi / 2;
        targetMsg.roll = 0;
        targets.publish(targetMsg);
        
        handMsg.width = 0.040;
        hand.publish(handMsg);

        sleep(25);
        //ROS_INFO("MOVE DOWN");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.005;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.064;
        //hand.publish(handMsg);

        //sleep(20);
        //ROS_INFO("GRIP");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.005;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.030;
        //hand.publish(handMsg);

        //sleep(20);
        //ROS_INFO("LIFT");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.100;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.030;
        //hand.publish(handMsg);

        //sleep(20);
        //ROS_INFO("DROP");

        //targetMsg.x = 0.400;
        //targetMsg.y = 0.000;
        //targetMsg.z = 0.100;
        //targetMsg.pitch = 0;
        //targetMsg.roll = 0;
        //targets.publish(targetMsg);
        //
        //handMsg.width = 0.64;
        //hand.publish(handMsg);

        //sleep(20);
    }
}
