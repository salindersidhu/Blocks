/*
FILENAME:		Constants.h
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Macros, definitions and enumerations.
UPDATE DATE:	12/22/2015
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Window constants
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 700
#define BITS_PER_PIXEL 32
#define FRAMERATE 60
#define WINDOW_TITLE "Blocks"

// Game constants
#define GAME_INIT_X 55
#define GAME_INIT_Y 167
#define GAME_POS_INCR 80
#define BLOCK_VICTORY_POS 375
#define GAME_RESOURCE_ARCHIVE "Data.7z"
#define RESET_BUTTON_TEXT "Restart"
#define QUIT_BUTTON_TEXT "Quit"
#define GAME_WON_MESSAGE "Congratulations!\nYou have completed all the levels!"
enum ORIENTATION {V, H};

// Resource paths
#define IMAGE_BACKGROUND "levelbg.png"
#define FONT_COOPER_BLACK_STD "CooperBlackStd.otf"
#define IMAGE_BUTTON "button.png"
#define IMAGE_BUTTON_SELECTED "button_select.png"
#define IMAGE_BH21 "bh21.png"
#define IMAGE_BH22 "bh22.png"
#define IMAGE_BH23 "bh23.png"
#define IMAGE_BH24 "bh24.png"
#define IMAGE_BH25 "bh25.png"
#define IMAGE_BH26 "bh26.png"
#define IMAGE_BV21 "bv21.png"
#define IMAGE_BV22 "bv22.png"
#define IMAGE_BV23 "bv23.png"
#define IMAGE_BV24 "bv24.png"
#define IMAGE_BV25 "bv25.png"
#define IMAGE_BV26 "bv26.png"
#define IMAGE_BH31 "bh31.png"
#define IMAGE_BH32 "bh32.png"
#define IMAGE_BV31 "bv31.png"
#define IMAGE_BV32 "bv32.png"

// Resource IDs
enum SPRITE {LEVELBG, BUTTON_RESET_NORMAL, BUTTON_RESET_SELECTED, BUTTON_QUIT_NORMAL, BUTTON_QUIT_SELECTED, BH21, BH22, BH23, BH23_2, BH24, BH25, BV25_2, BH26, BV21, BV22, BV22_2, BV23, BV24, BV25, BV26, BH31, BH32, BV31, BV32_2, BV32, BH32_2};
enum TEXTS {HEADER, INFO, BUTTON_RESET, BUTTON_QUIT};

// SFML specific
#define LIGHT_RED sf::Color(255, 51, 82)
#define WHITE sf::Color(255 ,255, 255)

#endif