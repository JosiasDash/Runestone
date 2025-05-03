cmake_minimum_required(VERSION 3.15)
project(Runestone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Indiquer explicitement le répertoire où SFML est installé par Conan
# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/SFML")

set(SRCS src/main.cpp src/Game.cpp)
include_directories("include")

# find_package(RAYLIB REQUIRED)

add_executable(Runestone ${SRCS})

# Lier les bibliothèques Raylib
target_link_libraries(Runestone PUBLIC raylib GL m pthread dl rt X11)