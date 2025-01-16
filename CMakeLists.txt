cmake_minimum_required(VERSION 3.30)
project(basic_calculator_sfml)

# C++20 standard settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)

# Boost
find_package(Boost 1.86.0 COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Source and header files
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include headers
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-network
        sfml-graphics
        sfml-window
        sfml-audio
        ${Boost_LIBRARIES})

# Compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(basic_calculator_sfml PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(basic_calculator_sfml PRIVATE /W4 /permissive-)
endif()

