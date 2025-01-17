# SO_LONG
so_long is a simple 2D game developed in the C programming language. The project serves as an introduction to graphical programming and game development concepts, utilizing the MiniLibX library for rendering graphics. The objective of the game is to navigate a character through a map, collect items, and reach an exit point.

## USAGE
Clone the Repository:

```bash
git clone https://github.com/jasonmgl/so_long.git
```
Navigate to the Directory:

```bash
cd so_long
```
Compile the Program:

Use the provided Makefile to compile the project:

```bash
make
```
or
```bash
make bonus
```
This will generate the executable so_long with or without bonus.

Run the Game:

Execute the program with a map file as an argument:

```bash
./so_long maps/your_map.ber
```
or
```bash
./so_long_bonus maps/your_map.ber
```
Replace your_map.ber with the path to your desired map file.

## DEPENDENCIES
- Compiler: Requires a C compiler like gcc.
- Make: Utilizes make for building the project.
- MiniLibX: Depends on the MiniLibX library for graphical rendering. Ensure that MiniLibX is properly installed on your system.

## DESCRIPTIONS
libft: Includes the libft library, providing essential utilities for string manipulation, memory management, and other helper functions.

maps: Houses map files used by the program to render different game levels.

minilibx-linux: Contains the MiniLibX library files necessary for graphical rendering on Linux systems.

sprites: Stores sprite images used for rendering the game characters and environment.
