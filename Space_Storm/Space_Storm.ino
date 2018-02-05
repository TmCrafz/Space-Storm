#include <Arduboy2.h>

Arduboy2 arduboy;

const unsigned int SCREEN_WIDTH = 128;
const unsigned int SCREEN_HEIGHT = 64;

const unsigned char PLAYER_SPRITE[] PROGMEM = {
    0x83, 0x83, 0xfe, 0x7c, 0x38, 0x38, 0x7c, 0xff, 0xff, 0x39, 0xc6, 0x38, 0x10, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00,
};
const unsigned int PLAYER_SPRITE_WIDTH = 13;
const unsigned int PLAYER_SPRITE_HEIGHT = 9;

void setup() {
    arduboy.begin();
    arduboy.clear();
}

void loop() {
    arduboy.clear();
    // params: posX, posY, image, width, height, COLOR (When white, all white pixels are drawn white)
    arduboy.drawBitmap(0, 0, PLAYER_SPRITE, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
    arduboy.display();
}
