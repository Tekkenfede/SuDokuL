cmake_minimum_required(VERSION 3.2)
project(sudokul CXX)

add_executable(sudokul
	"src/main.cpp"
	"src/config.h"
	"src/game_logic.h"
	"src/general.h"
	"src/include.h"
	"src/menu_logic.h"
	"src/puzzleBank.cpp"
	"src/puzzleBank.h"
	"src/shared.h"
	"src/sound_logic.h"
	"src/sprite_objects.h"
	"src/sudokuGen.cpp"
	"src/sudokuGen.h"
	"src/text_objects.h"
	"src/transitions.h"
)

# Doesn't work; use VS project file for Windows compilation
	target_link_libraries(sudokul SDL2_ttf SDL2_mixer SDL2_image SDL2 freetype)
	find_package(PkgConfig REQUIRED)
	target_link_libraries(sudokul PkgConfig::SDL2 PkgConfig::SDL2_image PkgConfig::SDL2_mixer PkgConfig::SDL2_ttf)
	target_link_options(sudokul PRIVATE -static-libgcc -static-libstdc++)
	add_definitions(-DSDL_MAIN_HANDLED)
