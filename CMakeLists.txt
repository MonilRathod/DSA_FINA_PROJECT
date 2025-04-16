cmake_minimum_required(VERSION 3.10.0)
project(spaceinvader VERSION 0.1.0 LANGUAGES C CXX)

list (APPEND CMAKE_PREFIX_PATH "C:/Users/M416/vcpkg/installed/x64-windows")

find_package(raylib CONFIG REQUIRED)

add_executable(spaceinvader main.cpp spaceship.cpp game.cpp laser.cpp block.cpp obstacle.cpp alien.cpp)
target_link_libraries(spaceinvader PRIVATE raylib)

