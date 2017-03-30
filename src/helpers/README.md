# Southern Arm Control Controllers > src > helpers

This folder holds the helper headers and source files for the controllers.

## Files
### config.h
* This file contains the globally applicable #defines for the controllers.

### selector.h
* The selector will allow for the interfacing with the menu for controller selection.
* Each controller must have a unique ID.
* The selector will create a subscriber and update the controller number.
* isSelected() can be used to check if the node has been selected or not.
