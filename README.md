# joytrack

Joystick music-making program, inspired by trackers.

This is a simple music tracker (sort of) that uses [imgui](https://github.com/ocornut/imgui) and [glfw](https://www.glfw.org/).

It takes inspiration from [Renoise](https://www.renoise.com/), [FastTracker2](https://en.wikipedia.org/wiki/FastTracker_2) and [ShieldTracker](https://bleep.toys/stracker/), as well as [M8](https://dirtywave.com/), which are all great, but I think it has it's own original flavor.

It's meant to be key-driven, configurable, and very cross-platform and fast on most modern devices. I use it on my SteamDeck running Linux.
## compiling

```
# configure
cmake -B build -G Ninja

# build
cmake --build build

# run
./build/joytrack
```
