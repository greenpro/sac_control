# Southern Arm Control Controllers

This project holds the controllers for the Southern Arm Control workspace.

## Installation

To install the Southern Arm Control system download sac_setup from https://github.com/greenpro/sac_setup.git and run the setup.sh script for Ubuntu or the rpiSetup.sh script for Raspian.

## Files
CMakeList.txt
* This file holds the project configuration for building.

package.xml
* This file holds the project configuration for building.

## Folders
launch/
* This file holds the launch files for the project.
* The launch files should not reference launch files form any other project.
* The launch files should not be called directly (they should be called through the sac_launch project's launch files).

msg/
* This folder contains the custom message files for the project.

src/
* This folder contains the c++ controllers for the system.

scripts/
* This folder contains the python controllers for the system.

## Remove
* The config folder may need to be removed later.
