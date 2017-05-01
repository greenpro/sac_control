echo "Enter the api address (port 8080 will be used):"
read addr
echo "$addr"
    
gripWait=5
rotWait=9
rotWaitMore=18
liftWait=5

block2Grip=0.018
block1Grip=0.028
block0Grip=0.038

# move 0
    # blocks
    #     2
    #     1
    #     0
# turn to move over the block 2
# The first call is sent twice to overcome an error in the server.
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/0.065/0
sleep 1
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWaitMore

# lower onto the block 2
wget $addr:8080/0.000000/0.336000/0.0650000/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.000000/0.336000/0.0650000/0.000000/1.57079633/$block2Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# move the block to pos 2
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $rotWaitMore

# lower the block
wget $addr:8080/0.336000/0.000000/0.010000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.336000/0.000000/0.010000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait


# move 1
    # blocks
    #      
    #     1
    # 2   0
# turn to move over the block 1
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWaitMore

# lower onto the block 1
wget $addr:8080/0.000000/0.336000/0.042000/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.000000/0.336000/0.042000/0.000000/1.57079633/$block1Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/$block1Grip/0
sleep $liftWait

# move the block to pos2
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/$block1Grip/0
sleep $rotWait

# lower the block
wget $addr:8080/0.237558/0.237558/0.010000/0.000000/1.57079633/$block1Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.237558/0.237558/0.010000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait


# move 2
    # blocks
    #      
    #      
    # 2 1 0
# turn to move over the block 2
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWait

# lower onto the block 2
wget $addr:8080/0.336000/0.000000/0.000500/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.336000/0.000000/0.000500/0.000000/1.57079633/$block2Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# move the block to pos
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $rotWait

# lower the block
wget $addr:8080/0.237558/0.237558/0.040000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.237558/0.237558/0.040000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait
    

# move 3
    # blocks
    #      
    #   2  
    #   1 0
# turn to move over the block 0
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWait

# lower onto the block 0
wget $addr:8080/0.000000/0.336000/0.005000/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.000000/0.336000/0.005000/0.000000/1.57079633/$block0Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/$block0Grip/0
sleep $liftWait

# move the block to pos
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/$block0Grip/0
sleep $rotWaitMore

# lower the block
wget $addr:8080/0.336000/0.000000/0.010000/0.000000/1.57079633/$block0Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.336000/0.000000/0.010000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait


# move 4
    # blocks
    #      
    #   2  
    # 0 1  
# turn to move over the block 0
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWait

# lower onto the block 0
wget $addr:8080/0.237558/0.237558/0.040000/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.237558/0.237558/0.040000/0.000000/1.57079633/$block2Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# move the block to pos
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $rotWait

# lower the block
wget $addr:8080/0.000000/0.336000/0.010000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.000000/0.336000/0.010000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait


# move 5
    # blocks
    #      
    #      
    # 0 1 2
# turn to move over the block 0
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWait

# lower onto the block 0
wget $addr:8080/0.237558/0.237558/0.005000/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.237558/0.237558/0.005000/0.000000/1.57079633/$block1Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.237558/0.237558/0.200000/0.000000/1.57079633/$block1Grip/0
sleep $liftWait

# move the block to pos
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/$block1Grip/0
sleep $rotWait

# lower the block
wget $addr:8080/0.336000/0.000000/0.050000/0.000000/1.57079633/$block1Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.336000/0.000000/0.050000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait


# move 6
    # blocks
    #      
    # 1    
    # 0   2
# turn to move over the block 0
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/0.065/0
sleep $rotWaitMore

# lower onto the block 0
wget $addr:8080/0.000000/0.336000/0.005000/0.000000/1.57079633/0.065/0
sleep $liftWait

# close the hand on the block
wget $addr:8080/0.000000/0.336000/0.005000/0.000000/1.57079633/$block2Grip/0
sleep $gripWait

# lift up the block
wget $addr:8080/0.000000/0.336000/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# move the block to pos
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/$block2Grip/0
sleep $rotWaitMore

# lower the block
wget $addr:8080/0.336000/0.000000/0.080000/0.000000/1.57079633/$block2Grip/0
sleep $liftWait

# release the block
wget $addr:8080/0.336000/0.000000/0.080000/0.000000/1.57079633/0.065/0
sleep $gripWait

# lift the gripper
wget $addr:8080/0.336000/0.000000/0.200000/0.000000/1.57079633/0.065/0
sleep $liftWait
