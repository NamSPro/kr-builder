cmake_minimum_required(VERSION 3.10)

option(USE_TESTS "Include prepackaged tests" ON)
configure_file(config.h.in config.h)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2")
set(BASE_PACKAGE "lib" "calculator")

project(kr_builder VERSION 0.1)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_subdirectory(lib)
add_subdirectory(lib/calculator)
if(USE_TESTS)
	add_subdirectory(lib/tests)
	list(APPEND EXTRA_LIBS tests)
	list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/tests")
endif()


add_executable(kr_builder main.cpp)

target_link_libraries(kr_builder PUBLIC ${BASE_PACKAGE} ${EXTRA_LIBS})

target_include_directories(kr_builder PUBLIC
						   "${PROJECT_BINARY_DIR}"
						   "${PROJECT_SOURCE_DIR}/lib"
						   "${PROJECT_SOURCE_DIR}/lib/calculator"
						   "$EXTRA_INCLUDES")