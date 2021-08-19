#OBJS specifies which files to compile as part of the project
OBJS = main.cpp lib/texture_wrapper.cpp lib/calculator/option.cpp lib/calculator/gear.cpp lib/calculator/hero.cpp lib/calculator/percentage.cpp lib/calculator/soul_weapon.cpp lib/tests/tests.h

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IE:/sdl2/include/SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LE:/sdl2/lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -Wall -Wextra -std=c++14
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wall -Wextra -std=c++14

#LINKER_FLAGS specifies the libraries we're linking against
# -lmingw32 
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our executable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)