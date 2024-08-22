# cub3d

`cub3d` is a basic 3D game engine using ray-casting, inspired by the classic game Wolfenstein 3D. The project is written in C and uses the MiniLibX library for graphics rendering. The goal is to render a 3D environment based on a 2D map and allow basic player movement within that environment.

## Features

- Basic 3D rendering using ray-casting
- Simple player movement and view rotation
- Mini-map display
- Texture mapping for walls
- Support for different wall textures and floor/ceiling colors

## Getting Started

### Prerequisites

Ensure you have the following installed:

- **Make**: Used to build the project.
- **GCC**: The GNU Compiler Collection for compiling C programs.
- **MiniLibX**: A simple X-Window (X11) programming library.

#### Installing Dependencies

- **On Debian/Ubuntu**:

```bash
  sudo apt-get update
  sudo apt-get install make gcc libx11-dev libxext-dev
```
- **On macOS (using Homebrew)**:

To install the necessary dependencies, run:
```bash
brew install make gcc

brew install --cask xquartz
```
### Cloning the Repository
To get a local copy up and running, clone the repository using the following command:
```bash
git clone https://github.com/yourusername/cub3d.git
```
Then navigate into the project directory:
```bash
cd cub3d
```
### Building the Project
Once inside the project directory, build the project using make:
```bash
make
```
This will compile all the necessary source files and generate the cub3d executable.

### Running cub3d
After building the project, you can start the game with:
```bash
./cub3d maps/map.cub
```
Replace maps/map.cub with the path to your desired .cub map file. The game should launch and display the 3D environment.

- **Controls**:
- W: Move forward
- S: Move backward
- A: Strafe left
- D: Strafe right
- Left Arrow: Rotate view left
- Right Arrow: Rotate view right
- ESC: Exit the game
### Customizing Maps
To create or modify maps, edit the .cub files located in the maps/ directory. These files define the layout of walls, player start position, and other in-game elements.

### Exiting cub3d
To exit the game, press the ESC key.
