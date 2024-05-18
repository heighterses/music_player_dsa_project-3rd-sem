cmake_minimum_required(VERSION 3.27)
project(music_player_dsa_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(music_player_dsa_project main.cpp)

# Link against the Winmm library
target_link_libraries(music_player_dsa_project PRIVATE winmm)


