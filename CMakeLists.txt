cmake_minimum_required(VERSION 4.3)

project(phymath_sandbox
        VERSION 0.2.0
        DESCRIPTION "Physics, Math, Algo Simulation."
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF) # -std=c++23, а не -std=gnu++23

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

set(PHYMATH_APP_SOURCES
        src/main.cpp
        src/Application.cpp
        src/Application.h
        src/Body.cpp
        src/Body.h
)

add_executable(phymath_sandbox
        ${PHYMATH_APP_SOURCES}
)

#target_include_directories(phymath_sandbox PRIVATE src)
target_link_libraries(phymath_sandbox
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)