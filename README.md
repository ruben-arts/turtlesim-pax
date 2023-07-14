# Example package how to use pixi for a ros package

## Running ros2
You are now ready to clone this package and run the simulation

```
git clone https://github.com/ruben-arts/turtlesim-pixi.git

pixi run turtlesim
```
Open an extra terminal where you can run the teleop

```
pixi run teleop
```

And in another terminal you could open the rqt viewer. 

## Building colcon packages

```
# Run the custom build command to do a colcon build
pixi run build 

# The test command is also wrapped
pixi run test

# Run the custom command to do a ros2 run, this depends on build so that will always be ran first. 
# Note that the first time you run the build it will setup its own colcon environment. 
# This has to be re-enabled, rerun any commando to activate the environment including the activation scripts.

pixi run controller
# Now you should see the same turtlesim move in a circle.
```
