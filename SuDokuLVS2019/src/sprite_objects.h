#include "shared.h"

#ifndef SPRITE_OBJECTS_H
#define SPRITE_OBJECTS_H

#define SPRITE_PATH_TILE                     "graphics/tile.png"
#define SPRITE_PATH_LOGO_240                 "graphics/logo_240.png"
#define SPRITE_PATH_LOGO_272                 "graphics/logo_272.png"
#define SPRITE_PATH_LOGO_480                 "graphics/logo_480.png"
#define SPRITE_PATH_LOGO_544                 "graphics/logo_544.png"
#define SPRITE_PATH_LOGO_720                 "graphics/logo_720.png"
#define SPRITE_PATH_LOGO_1080                "graphics/logo_1080.png"
#define SPRITE_PATH_LOGO_1440                "graphics/logo_1440.png"
#define SPRITE_PATH_LOGO_2160                "graphics/logo_2160.png"
#define SPRITE_PATH_MENU_CURSOR              "graphics/menu_cursor.png"
#define SPRITE_PATH_GRID_384                 "graphics/grid_384.png"
#define SPRITE_PATH_GRID_CURSOR_BOTTOM_LEFT  "graphics/grid_cursor_bottom_left.png"
#define SPRITE_PATH_GRID_CURSOR_BOTTOM_RIGHT "graphics/grid_cursor_bottom_right.png"
#define SPRITE_PATH_GRID_CURSOR_TOP_LEFT     "graphics/grid_cursor_top_left.png"
#define SPRITE_PATH_GRID_CURSOR_TOP_RIGHT    "graphics/grid_cursor_top_right.png"
#define SPRITE_PATH_SIDEBAR_SMALL            "graphics/sidebar_small.png"
#define SPRITE_PATH_GRID_MINI_BOTTOM_LEFT    "graphics/grid_mini_bottom_left.png"
#define SPRITE_PATH_GRID_MINI_BOTTOM_RIGHT   "graphics/grid_mini_bottom_right.png"
#define SPRITE_PATH_GRID_MINI_TOP_LEFT       "graphics/grid_mini_top_left.png"
#define SPRITE_PATH_GRID_MINI_TOP_RIGHT      "graphics/grid_mini_top_right.png"

struct SpriteObject {
    SDL_Texture *texture;
    SDL_Rect rect;
    Sint32 width, height;
};

struct SpriteObjectWithPos {
    SDL_Texture *texture;
    SDL_Rect rect;
    Sint32 width, height;
    Sint16 startPos_x, endPos_x;
    Sint16 startPos_y, endPos_y;
};

/* Textures */
extern SpriteObject tile;
extern SpriteObjectWithPos logo;
extern SpriteObjectWithPos menuCursor;
extern SpriteObject game_grid;
//extern SpriteObjectWithPos gridCursor;
extern SpriteObjectWithPos gridCursor_bottom_left;
extern SpriteObjectWithPos gridCursor_bottom_right;
extern SpriteObjectWithPos gridCursor_top_left;
extern SpriteObjectWithPos gridCursor_top_right;
extern SpriteObject game_sidebar_small;

extern SpriteObjectWithPos miniGrid_bottom_left;
extern SpriteObjectWithPos miniGrid_bottom_right;
extern SpriteObjectWithPos miniGrid_top_left;
extern SpriteObjectWithPos miniGrid_top_right;
extern SpriteObjectWithPos *currMiniGrid;

#define PREPARE_SPRITE(spriteObj, spriteImage, pos_x, pos_y, scale)                       \
    spriteObj.texture = IMG_LoadTexture(renderer, (rootDir + spriteImage).c_str());       \
    SDL_QueryTexture(spriteObj.texture, NULL, NULL, &spriteObj.width, &spriteObj.height); \
    SET_SPRITE_SCALE(spriteObj, scale);                                                   \
    spriteObj.rect.x = pos_x;                                                             \
    spriteObj.rect.y = pos_y;

#define SET_SPRITE_SCALE(spriteObj, scale)                                                      \
    spriteObj.rect.w = (int)(spriteObj.width * min(GAME_WIDTH_MULT, GAME_HEIGHT_MULT) * scale); \
    spriteObj.rect.h = (int)(spriteObj.height * min(GAME_WIDTH_MULT, GAME_HEIGHT_MULT) * scale);

#define SPRITE_ENFORCE_INT_MULT(spriteObj, scale)                                                            \
    spriteObj.rect.w = (int)(spriteObj.width * ((int)ceil(min(GAME_WIDTH_MULT, GAME_HEIGHT_MULT))) * scale); \
    spriteObj.rect.h = (int)(spriteObj.height * ((int)ceil(min(GAME_WIDTH_MULT, GAME_HEIGHT_MULT))) * scale);

#define SET_SPRITE_SCALE_TILE()                  \
    tile.rect.w = tile.width * bgSettings.scale; \
    tile.rect.h = tile.height * bgSettings.scale;

#define OBJ_TO_MID_SCREEN_X(obj) \
    ((gameWidth - obj.rect.w) / 2)

#define OBJ_TO_SCREEN_AT_FRACTION(obj, val) \
    ((gameWidth * val) - (obj.rect.w / 2))

#define OBJ_TO_MID_SIDEBAR(obj) \
    (game_sidebar_small.rect.x + (game_sidebar_small.rect.w - obj.rect.w) / 2)

#endif