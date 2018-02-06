#include <Arduboy2.h>
#include "Vector2.hpp"

Arduboy2 arduboy;

const unsigned int SCREEN_WIDTH = 128;
const unsigned int SCREEN_HEIGHT = 64;

const unsigned char PLAYER_SPRITE[] PROGMEM = {
    0x83, 0x83, 0xfe, 0x7c, 0x38, 0x38, 0x7c, 0xff, 0xff, 0x39, 0xc6, 0x38, 0x10, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00,
};
const unsigned int PLAYER_SPRITE_WIDTH = 13;
const unsigned int PLAYER_SPRITE_HEIGHT = 9;

int playerPosX = 0;
int playerPosY = 0;

void setup()
{
    arduboy.begin();
    arduboy.initRandomSeed();
    arduboy.clear();
}

void loop()
{
    // Needed for using justPressed() method
    arduboy.pollButtons();
    if (arduboy.pressed(UP_BUTTON)) {
        playerPosY--;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
        playerPosY++;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
        playerPosX--;
    }  
    if (arduboy.pressed(RIGHT_BUTTON)) {
        playerPosX++;
    }
    arduboy.clear();    
    // params: posX, posY, image, width, height, COLOR (When white, all white pixels are drawn white)
    arduboy.drawBitmap(playerPosX, playerPosY, PLAYER_SPRITE, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
    arduboy.display();
}
