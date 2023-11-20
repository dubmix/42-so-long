# So Long

This project is about coding a very small 2D game in C. Its purpose was to make us discover textures, sprites 
and some very basic gameplay elements, like window management, event handling, colors...

The goal of my game is for Eevee to collect all items and reach her trainer without stepping on any Silcoons. 
Like I said, pretty basic ;) The map of the game is generated from a .ber file in the `maps` folder. Each element
of the map is represented by a character, i.e. `1` is a wall element, `e` is a collectible, and so forth:

![so_long1](https://github.com/dubmix/42-so-long/assets/104844198/64a9d3e9-a808-40a9-b18b-a2757b7c92ff)

Here are a few screenshots of the end result:

![so_long2](https://github.com/dubmix/42-so-long/assets/104844198/d5fbf664-6c94-4ff4-842a-851825f4fdc2)

![so_long3](https://github.com/dubmix/42-so-long/assets/104844198/8d420c4d-d4af-4b60-a9ec-550983e469ec)

## Usage

Warning: `Makefile` is configured for `Linux` use only.

> - Compile with `make`. If `minilibx` hasn't be installed yet, it will happen automatically
> - Then run with `./so_long` + `map name` | Example: `./push_swap maps/map1.ber`
> - Move Eevee with the arrow keys
> - Exit the game at any time by pressing `esc` or by closing the window

## Restrictions

This project is written in C and 42 norm compliant:

> - All variables have to be declared and aligned at the top of each function
> - One function cannot have more than 25 lines
> - One file cannot have more than 5 functions
> - It is considering cheating to use functions that are forbidden in the subject
