#include <Arduboy2.h>
#include "Vector2.hpp"
#include "Entity.hpp"
#include "ImageData.hpp"

Arduboy2 arduboy;

const unsigned int SCREEN_WIDTH = 128;
const unsigned int SCREEN_HEIGHT = 64;

Entity player;

void setup()
{
    arduboy.begin();
    arduboy.initRandomSeed();
    arduboy.clear();
    
    player.setSprite(ImageData::PLAYER_SPRITE, ImageData::PLAYER_SPRITE_WIDTH, 
    ImageData::PLAYER_SPRITE_HEIGHT);
}

void loop()
{
    // Needed for using justPressed() method
    arduboy.pollButtons();
    int playerPosX = player.getPosition().x;
    int playerPosY = player.getPosition().y;
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
    player.setPosition(playerPosX, playerPosY);
    arduboy.clear();
    
    player.draw(arduboy);
    arduboy.display();
}
