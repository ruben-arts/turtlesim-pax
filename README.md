# Example package how to use pixi for a ROS2 workspace

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

```
pixi run rqt
```

## Building colcon packages

```
# Run the custom build command to do a colcon build
pixi run build 

# Run the custom command to do a ros2 run, this depends on build so that will always be ran first. 
# Note that the first time you run the build it will setup its own colcon environment. 
# This has to be re-enabled, rerun any commando to activate the environment including the activation scripts.

pixi run start
# Now you should see a turtlesim move in a square. This is done using a launch file.
```

Checkout the `pixi.toml` for more tasks you can execute. 


## Workspace setup.
The pixi project is a complete ROS2 workspace including two package `turtle_controller_cpp_py` and `turtle_controller_py` where one is a `ament_cmake` package and the other a `ament_python` package. This is done to just give an example on how to do a minimal setup for both types.

