# Example package how to use pixi for a ros package

# First: Get pixi
Make sure you have the latest version of pixi

Clone the repo:
```
git clone https://github.com/prefix-dev/pixi
```

Install it
```
cargo install --path pixi
```

# Second: Installing dependencies
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

# Third: Building colcon packages

```
# Run the custom build command to do a colcon build
pixi run build 

# The test command is also wrapped
pixi run test

# Run the custom command to do a ros2 run
pixi run controller
# Now you should see the same turtlesim move in a circle.
```
