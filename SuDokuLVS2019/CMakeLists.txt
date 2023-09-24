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
    # Set the target architecture to aarch64
    set(CMAKE_SYSTEM_PROCESSOR "aarch64")

    target_link_libraries(sudokul
        ${CMAKE_CURRENT_LIST_DIR}/SDL2/SDL2-2.0.14/lib/aarch64
        ${CMAKE_CURRENT_LIST_DIR}/SDL2/SDL2_image-2.0.5/lib/aarch64
        ${CMAKE_CURRENT_LIST_DIR}/SDL2/SDL2_mixer-2.0.4/lib/aarch64
        ${CMAKE_CURRENT_LIST_DIR}/SDL2/SDL2_ttf-2.0.15/lib/aarch64
    )

    find_package(PkgConfig REQUIRED)
    target_link_libraries(sudokul
        PkgConfig::SDL2
        PkgConfig::SDL2_image
        PkgConfig::SDL2_mixer
        PkgConfig::SDL2_ttf
    )
    
    target_link_options(sudokul PRIVATE -static-libgcc -static-libstdc++)
    add_definitions(-DSDL_MAIN_HANDLED)
