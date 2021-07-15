#OBJS specifies which files to compile as part of the project
OBJS = main.cpp lib\texture_wrapper.cpp lib\option.cpp lib\gear.cpp lib\hero.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IE:\SDL2-2.0.14\i686-w64-mingw32\include\SDL2 -IE:\SDL2_image-2.0.5\i686-w64-mingw32\include\SDL2 -IE:\SDL2_ttf-2.0.15\i686-w64-mingw32\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LE:\SDL2-2.0.14\i686-w64-mingw32\lib -LE:\SDL2_image-2.0.5\i686-w64-mingw32\lib -LE:\SDL2_ttf-2.0.15\i686-w64-mingw32\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -Wall -Wextra -std=c++14
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wall -Wextra -std=c++14

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our executable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)