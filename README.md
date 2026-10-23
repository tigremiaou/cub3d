*This project has been created as part of the 42 curriculum by nmeunier, hulescur.*

# cub3D

## Description

cub3D is a small 3D game engine written in C, inspired by the legendary *Wolfenstein 3D* (1992). The goal of the project is to render a first-person view of a maze from a 2D map using the **raycasting** technique, with the **MiniLibX** graphics library.

The program reads a scene description file (`.cub`) containing:
- the paths to the four wall textures (North, South, West, East),
- the floor and ceiling colors (RGB),
- the map itself, made of walls (`1`), empty space (`0`) and the player's starting position and orientation (`N`, `S`, `E`, `W`).

The file is fully parsed and validated (texture paths, color ranges, map closed by walls, single player, etc.). Any error makes the program exit cleanly with `Error\n` followed by an explicit message.

### Main features
- Raycasting engine using the DDA algorithm
- Textured walls, different texture depending on wall orientation
- Configurable floor and ceiling colors
- Smooth movement and camera rotation
- Clean exit with `ESC` or the window's close button
- No memory leaks

## Instructions

### Requirements
- Linux (or macOS with the matching MiniLibX version)
- `cc`, `make`
- X11 development libraries (`libx11-dev`, `libxext-dev`) on Linux

### Compilation
```bash
make        # build cub3D
make clean  # remove object files
make fclean # remove object files and binary
make re     # rebuild everything
```

### Execution
```bash
./cub3D maps/<map_name>.cub
```

### Controls
| Key | Action |
|-----|--------|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Rotate the camera |
| `ESC` | Quit |

### Example `.cub` file
```
NO ./textures/cosmos_north.xpm
SO ./textures/cosmos_south.xpm
WE ./textures/cosmos_west.xpm
EA ./textures/cosmos_east.xpm

F 40,40,50
C 10,10,30

111111
100001
1010N1
100001
111111
```

## Resources

### References
- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [Permadi – Ray-Casting Tutorial for Game Development](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [MiniLibX documentation (harm-smits)](https://harm-smits.github.io/42docs/libs/minilibx)
- [DDA line algorithm – Wikipedia](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
- [Wolfenstein 3D – Wikipedia](https://en.wikipedia.org/wiki/Wolfenstein_3D)

### Use of AI
AI tools were used as a learning and support aid, not to write the core of the project:
- **Understanding concepts**: explanations of raycasting, the DDA algorithm and texture mapping maths.
- **Texture design**: assistance in creating the themed textures.
- **Documentation**: help writing and formatting this README.

All code was written, reviewed and understood by both team members.