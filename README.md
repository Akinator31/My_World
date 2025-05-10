# My World - 3D Map Editor

A 3D terrain editor made with CSFML that allows you to create, modify and visualize 3D landscapes in an isometric view.

![image](https://github.com/user-attachments/assets/c6ad4327-3e8b-4b40-85d2-0e6aebbca7cf)

## Overview

My World is a 3D map editor that lets you create and edit terrain maps in real-time. The project uses the CSFML graphics library to render an isometric view of the terrain that can be modified through various tools and controls.

## Features

- **Map Creation**
  - Create maps of different sizes (10x10, 50x50, 100x100)
  - Load/Save map functionality
  - Custom map size option

- **Terrain Editing**
  - Raise/Lower terrain with mouse input
  - Flatten selected areas
  - Multiple editing tools:
    - Pen tool for precise editing
    - Up/Down tools for height modification
    - Flatten tool for leveling terrain

- **Visualization**
  - Isometric 3D view
  - Dynamic terrain coloring based on height
  - Camera controls:
    - Rotation (A/E keys)
    - Pan (Arrow keys)
    - Zoom (P/M keys)

- **Interface**
  - Main menu with multiple options
  - Settings menu with:
    - Resolution options (900p, 1080p, 4K)
    - Sound controls
    - Music toggle
  - In-game UI with editing tools

## Controls

### Camera Controls
- `Arrow Keys`: Move camera
- `A/E`: Rotate view
- `P/M`: Zoom in/out

### Editing Controls
- `Left Mouse Button`: Select and modify terrain
- `Z`: Raise terrain
- `S`: Lower terrain
- `F`: Flatten selected area

### General Controls
- `ESC`: Back to menu
- `Q`: Quit game

## Technical Features

- Written in C using CSFML graphics library
- Event-driven architecture
- Multi-threaded event handling
- Resource management system
- Scene management system
- Entity component system
- Dynamic memory management
- Collision detection system

## Building the Project

```bash
# Clone the repository
git clone https://github.com/yourusername/my_world.git

# Build the project
make

# Run the editor
./my_world
```

## Requirements

- CSFML library
- GCC compiler
- Make build system

## Project Structure

```
my_world/
├── assets/         # Game resources (images, sounds, fonts)
├── include/        # Header files
├── lib/           # Project libraries
├── src/           # Source files
└── tests/         # Unit tests
```
