- This file holds the C++ files for the robot control.

- The usb.cpp node controls all of the USB communications to the microcontroller. ROS will queue up the messages to the controller allowing the communication to the USB to be uninterrupted or denied during a transmission.

- The [alpha - Zeta]motor.cpp node sends the motor mesages to the usb node and the simulator. It will also check the angles are valid and transmit a message if they are not.

- Some of the content for the files comes from the ROS and MoveIt! tutorials

- Much of the code from the jacobian.cpp file comes from the github ros-planning in the moveit_tutorials -> doc -> pr2_tutorials -> planning -> src -> motion_planning_api_tutorial.cpp file.
