cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_PREFIX_PATH "E:/sdl")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2")

project(kr_builder VERSION 0.1)

configure_file(config.h.in config.h)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_subdirectory(lib)
add_subdirectory(lib/calculator)
add_subdirectory(lib/tests)

add_executable(kr_builder main.cpp)

target_link_libraries(kr_builder PUBLIC lib calculator tests)

target_include_directories(kr_builder PUBLIC
						   "${PROJECT_BINARY_DIR}"
						   "${PROJECT_SOURCE_DIR}/lib"
						   "${PROJECT_SOURCE_DIR}/lib/calculator"
						   "${PROJECT_SOURCE_DIR}/tests")