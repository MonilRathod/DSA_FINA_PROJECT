# Space Invaders Game

A modern implementation of the classic **Space Invaders** game built using the **Raylib** library. This project is designed to provide an engaging gaming experience with smooth gameplay, retro visuals, and sound effects.

## Table of Contents
- [Features](#features)
- [Setup Instructions](#setup-instructions)
- [How to Play](#how-to-play)
- [Project Structure](#project-structure)
- [Future Enhancements](#future-enhancements)
- [Credits](#credits)

---

## Features

### Current Features
1. **Player Spaceship**:
   - Move left and right to dodge alien lasers.
   - Fire lasers to destroy aliens.
   - Lives system with a visual indicator.

2. **Aliens**:
   - Multiple rows of aliens with different types and scores.
   - Aliens move horizontally and drop down when reaching the screen edges.
   - Aliens fire lasers at random intervals.

3. **Obstacles**:
   - Destructible obstacles that provide cover for the player.
   - Obstacles degrade when hit by lasers.

4. **Mystery Ship**:
   - A special ship that appears randomly and awards bonus points when destroyed.

5. **Scoring System**:
   - Tracks the player's score and displays it on the screen.
   - High score tracking with persistent storage in a file.

6. **Audio**:
   - Background music and sound effects for explosions and lasers.

7. **Game Over and Restart**:
   - Displays "Game Over" when the player loses all lives.
   - Allows restarting the game by pressing `Enter`.

---

## Setup Instructions

### Prerequisites
- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., GCC, MSVC).
- **CMake**: Install CMake to configure and build the project.
- **Raylib**: The project uses the Raylib library for graphics and audio. Install it via [vcpkg](https://github.com/microsoft/vcpkg).

### Steps to Build and Run
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/space-invaders.git
   cd space-invaders
