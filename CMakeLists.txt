cmake_minimum_required(VERSION 3.20)

project(
    basic_calculator_sfml
    VERSION 1.0.0
    DESCRIPTION "A desktop calculator built with C++ and SFML"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(Boost REQUIRED)

add_executable(
    basic_calculator_sfml
    src/main.cpp
    src/App.cpp
    src/Button.cpp
    src/Calculator.cpp
    src/Display.cpp
)

target_include_directories(
    basic_calculator_sfml
    PRIVATE
        include
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
    basic_calculator_sfml
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(basic_calculator_sfml PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(basic_calculator_sfml PRIVATE /W4 /permissive-)
endif()
