#include <Arduboy2.h>
#include "Vector2.hpp"
#include "Entity.hpp"
#include "ImageData.hpp"

Arduboy2 arduboy;

const unsigned int SCREEN_WIDTH = 128;
const unsigned int SCREEN_HEIGHT = 64;

Entity player;

// DeltaTime / FPS
long timeStampLast;
float averageFpsTime = 0.f;
float fpsInSec = 0;
int fpsCnt = 0;
int averageFpsPerSec = 0;

float determineDeltaTime()
{
    long timeStampCurrent = millis();
    float deltaTime = (timeStampCurrent - timeStampLast) / 1000.f;
    timeStampLast = timeStampCurrent;
    float fps = 1.f / deltaTime;
    averageFpsTime += deltaTime;
    fpsInSec += fps;
    fpsCnt++;
    if (averageFpsTime >= 1.f)
    {
        averageFpsPerSec = fpsInSec / fpsCnt + 0.5f;
        averageFpsTime = 0.f;
        fpsInSec = 0.f;
        fpsCnt = 0;
    }
    return deltaTime;
}

void setup()
{
    arduboy.begin();
    arduboy.initRandomSeed();
    arduboy.clear();
    
    player.setSprite(ImageData::PLAYER_SPRITE, ImageData::PLAYER_SPRITE_WIDTH, 
    ImageData::PLAYER_SPRITE_HEIGHT);
    
    timeStampLast = millis();
}

void loop()
{
    float dt = determineDeltaTime();
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
    // Draw Fps
    arduboy.setCursor(0, 0);
    arduboy.print("FPS: ");
    arduboy.print(averageFpsPerSec);
    
    arduboy.display();
}
