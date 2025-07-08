cmake_minimum_required(VERSION 3.28)
project(finnishwordgame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(finnishwordgame main.cpp
        WordGame.cpp
        WordGame.h
        UI.cpp
        UI.h)

target_link_libraries(finnishwordgame SFML::Graphics)
