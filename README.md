# Example package how to use pax for a ros package

# First
Make sure you have the latest version of pax

Clone the repo:
```
git clone https://github.com/prefix-dev/pax
```

Install it
```
cargo install --path pax
```

# Second
You are now ready to clone this package and run the simulation

```
git clone https://github.com/ruben-arts/turtlesim-pax.git

pax run turtlesim
```
Open an extra terminal where you can run the teleop

```
pax run teleop
```

And in another terminal you could open the rqt viewer. 

