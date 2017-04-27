// loop for the controller issuing commands to the rest of the system
// callback for the menu selector int32
#include "helpers/config.h"
#include "helpers/selector.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <shape_msgs/SolidPrimitive.h>
#include <sac_msgs/Target.h>
#include <sac_msgs/Path.h>
#include <sac_msgs/HandPos.h>

namespace towers
{
    // constants
    const char *nodeName = "towers_of_hanoi_controller";
    const int controllerNum = 1;
    const float pi = 3.1415926535898;
    const char *planningGroup = "arm";
    
    // wait times (if running on a vm these may need to be increased.)
    const int gripWait = 10; // time for the gripper to open and close.
    const int rotWait = 9; // time for the gripper to rotate between targets
    const int liftWait = 5; // time for the gripper to raise and lower

    // grip widths
    const float block2Grip = 0.018;
    const float block1Grip = 0.028;
    const float block0Grip = 0.038;

    // variables
    bool enabled = true; // change this to false later if this is not the default node.
    selector *sel;

    // publishers
    ros::Publisher targets;
    ros::Publisher hand;
}

void move(float x, float y, float z, 
	  float roll, float pitch, float hand)
{
    // Arm movement
    sac_msgs::Target targetMsg;
    
    targetMsg.x = x;
    targetMsg.y = y;
    targetMsg.z = z;
    targetMsg.pitch = pitch;
    targetMsg.roll = roll;
    towers::targets.publish(targetMsg);
    
    // Hand movement
    sac_msgs::HandPos handMsg;
    
    handMsg.width = hand;
    towers::hand.publish(handMsg);
}

void move0()
{
	// blocks
        //     2
	//     1
        //     0
    // turn to move over the block 2
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait * 2);
    
    // lower onto the block 2
    move(0.000000, 0.336000, 0.065000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.000000, 0.336000, 0.065000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // move the block to pos 2
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::rotWait * 2);
    
    // lower the block
    move(0.336000, 0.000000, 0.010000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.336000, 0.000000, 0.010000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        //      
	//     1
        // 2   0
}

void move1()
{
	// blocks
        //      
	//     1
        // 2   0
    // turn to move over the block 1
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait * 2);
    
    // lower onto the block 1
    move(0.000000, 0.336000, 0.042000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.000000, 0.336000, 0.042000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::liftWait);
    
    // move the block to pos2
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::rotWait);
    
    // lower the block
    move(0.237558, 0.237558, 0.010000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.237558, 0.237558, 0.010000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        //      
	//      
        // 2 1 0
}

void move2()
{
	// blocks
        //      
	//      
        // 2 1 0
    // turn to move over the block 2
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait);
    
    // lower onto the block 2
    move(0.336000, 0.000000, 0.000500, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.336000, 0.000000, 0.000500, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // move the block to pos
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::rotWait);
    
    // lower the block
    move(0.237558, 0.237558, 0.040000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.237558, 0.237558, 0.040000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        //      
	//   2  
        //   1 0
}

void move3()
{
	// blocks
        //      
	//   2  
        //   1 0
    // turn to move over the block 0
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait);
    
    // lower onto the block 0
    move(0.000000, 0.336000, 0.005000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.000000, 0.336000, 0.005000, 
         0.000000, towers::pi / 2, towers::block0Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, towers::block0Grip);
    sleep(towers::liftWait);
    
    // move the block to pos
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, towers::block0Grip);
    sleep(towers::rotWait * 2);
    
    // lower the block
    move(0.336000, 0.000000, 0.010000, 
         0.000000, towers::pi / 2, towers::block0Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.336000, 0.000000, 0.010000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        //      
	//   2  
        // 0 1  
}

void move4()
{
	// blocks
        //      
	//   2  
        // 0 1  
    // turn to move over the block 0
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait);
    
    // lower onto the block 0
    move(0.237558, 0.237558, 0.040000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.237558, 0.237558, 0.040000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // move the block to pos
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::rotWait);
    
    // lower the block
    move(0.000000, 0.336000, 0.010000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.000000, 0.336000, 0.010000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        //      
	//      
        // 0 1 2
}

void move5()
{
	// blocks
        //      
	//      
        // 0 1 2
    // turn to move over the block 0
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait);
    
    // lower onto the block 0
    move(0.237558, 0.237558, 0.005000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.237558, 0.237558, 0.005000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.237558, 0.237558, 0.200000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::liftWait);
    
    // move the block to pos
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::rotWait);
    
    // lower the block
    move(0.336000, 0.000000, 0.050000, 
         0.000000, towers::pi / 2, towers::block1Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.336000, 0.000000, 0.050000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        //      
	// 1    
        // 0   2
}

void move6()
{
	// blocks
        //      
	// 1    
        // 0   2
    // turn to move over the block 0
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::rotWait * 2);
    
    // lower onto the block 0
    move(0.000000, 0.336000, 0.005000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
    
    // close the hand on the block
    move(0.000000, 0.336000, 0.005000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::gripWait);
    
    // lift up the block
    move(0.000000, 0.336000, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // move the block to pos
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::rotWait * 2);
    
    // lower the block
    move(0.336000, 0.000000, 0.080000, 
         0.000000, towers::pi / 2, towers::block2Grip);
    sleep(towers::liftWait);
    
    // release the block
    move(0.336000, 0.000000, 0.080000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::gripWait);
    
    // lift the gripper
    move(0.336000, 0.000000, 0.200000, 
         0.000000, towers::pi / 2, 0.065);
    sleep(towers::liftWait);
	// blocks
        // 2    
	// 1    
        // 0    
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, towers::nodeName);

    ros::NodeHandle nh;

    towers::targets = nh.advertise<sac_msgs::Target>("/moveto", 1000);
    towers::hand = nh.advertise<sac_msgs::HandPos>("/handDriver", 1000);

    sleep(15);
    while (towers::enabled)
    {
	// lift into place
	move(0.336000, 0.000000, 0.200000, 
	     0.000000, towers::pi / 2, 0.065);
        sleep(towers::liftWait);

	move0();
	move1();
	move2();
	move3();
	move4();
	move5();
	move6();
    }
}
