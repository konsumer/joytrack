# joytrack

Joystick music-making program, inspired by trackers.

This is a simple music tracker (sort of) that is written in [nelua](https://nelua.io/) and uses [Raylib.nelua](https://github.com/AuzFox/Raylib.nelua).

It takes inspiration from [Renoise](https://www.renoise.com/), [FastTracker2](https://en.wikipedia.org/wiki/FastTracker_2) and [ShieldTracker](https://bleep.toys/stracker/), as well as [M8](https://dirtywave.com/), which are all great, but I think it has it's own original flavor.

It's meant to be key-driven, configurable, and very cross-platform and fast on most modern devices. I use it on my SteamDeck running Linux.

## dependencies

You will need nelua, raylib, and a C compiler installed. On Nobara Linux (similar to Fedora or CentOS) I did this:

```
# install raylib & build-deps
sudo dnf install raylib-devel git make gcc

# install nelua
cd /tmp
git clone https://github.com/edubart/nelua-lang.git
cd nelua-lang
make
sudo make install
```

After this, you should be able to run `nelua` in any directory. If not refer to [nelua docs](https://nelua.io/installing/).

## running

After you have raylib and nelua installed, you should be able to run like this:

```
nelua --add-path src src/joytrack.nelua
```

## compiling

This is how I compile for [releases](https://github.com/konsumer/joytrack/releases):

```
nelua --add-path src src/joytrack.nelua -b -o build/joytrack --release -P nochecks
```
