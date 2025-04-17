
# Space Invaders Game

A modern implementation of the classic **Space Invaders** game built using the **Raylib** library. This project aims to provide a fun and engaging arcade experience with retro visuals, sound effects, and smooth gameplay.

---

## 📑 Table of Contents

- [Features](#-features)
- [Setup Instructions](#setup-instructions)
- [How to Play](#how-to-play)
- [Project Structure](#project-structure)
- [Future Enhancements](#future-enhancements)
- [Credits](#credits)


---

## 🧠 features

### ✅ Current Functionality

- **Player Spaceship**
  - Move left/right
  - Fire lasers
  - Visual life counter

- **Alien Enemies**
  - Multiple rows with types and score values
  - Horizontal movement with screen edge descent
  - Randomized alien laser attacks

- **Obstacles**
  - Destructible cover blocks for player defense

- **Mystery Ship**
  - Appears randomly and gives bonus score when destroyed

- **Score System**
  - Live score display
  - Persistent high score saved to file

- **Audio**
  - Background music
  - Sound effects for shooting, explosions, etc.

- **Game Over / Restart**
  - Ends on player death or alien breach
  - Press `Enter` to restart the game

---

## ⚙️ Setup Instructions

### Prerequisites

- C++ Compiler (GCC, Clang, or MSVC)
- [CMake](https://cmake.org/) ≥ 3.15
- [Raylib](https://www.raylib.com/) (Install via [vcpkg](https://github.com/microsoft/vcpkg))

### 🔧 Build & Run

# Clone the repository
git clone https://github.com/MonilRathod/DSA_FINA_PROJECT
cd DSA_FINA_PROJECT

# Configure with CMake
cmake -S . -B build

# Build the project
cmake --build build

# Run the game
./build/spaceinvader


---

## 🎮 How to Play

| Action        | Key           |
|---------------|---------------|
| Move          | ← / → Arrows  |
| Fire          | Spacebar      |
| Restart       | Enter (on Game Over) |

### 🎯 Objective

Destroy all aliens before they reach the bottom. Avoid getting hit by their lasers. Use the obstacles as temporary protection.

---

## 🗂 Project Structure


DSA_FINA_PROJECT/
├── graphics/                # Sprites and textures
├── sound/                   # Sound effects and music
├── src/                     # Source code files
│   ├── main.cpp             # Game entry point
│   ├── game.cpp             # Core game loop and logic
│   ├── spaceship.cpp        # Player spaceship logic
│   ├── alien.cpp            # Alien behavior
│   ├── obstacle.cpp         # Obstacle mechanics
│   ├── laser.cpp            # Laser projectile logic
│   └── block.cpp            # Individual block unit
├── include/                 # Header files
│   ├── game.hpp
│   ├── spaceship.hpp
│   ├── alien.hpp
│   ├── obstacle.hpp
│   ├── laser.hpp
│   └── block.hpp
├── CMakeLists.txt           # Build configuration
└── README.md                # Project documentation


---

## 🚧 Future Enhancements

- **Power-Ups**
  - Double lasers
  - Shields
  - Speed boosts

- **Levels & Difficulty**
  - Increasing speed and firing rate
  - Multiple waves with difficulty scaling

- **Multiplayer Mode**
  - Co-op or vs gameplay

- **Boss Battles**
  - Unique boss enemies with health bars

- **Improved Visuals**
  - Better textures, explosion animations

- **Custom Controls**
  - Configurable key mappings

- **Achievements & Leaderboards**
  - Milestone rewards
  - Global score ranking

- **Mobile Port**
  - Touch controls for Android/iOS

- **Story Mode**
  - Cutscenes, missions, progression

- **AI Improvements**
  - Smarter alien patterns and shooting logic

---

## 👨‍💻 Credits

- **Developer**: Code with Nick  
- **Graphics**: Created using [Raylib](https://www.raylib.com/)  
- **Audio**: Sourced from [freesound.org](https://freesound.org)

---

> 🚀 If you enjoy this project, consider starring it or suggesting improvements!
```
