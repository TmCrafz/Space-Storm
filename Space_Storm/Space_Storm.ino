#include <Arduboy2.h>
#include "Vector2.hpp"
#include "Entity.hpp"
#include "ImageData.hpp"

Arduboy2 arduboy;

const unsigned int SCREEN_WIDTH = 128;
const unsigned int SCREEN_HEIGHT = 64;

Entity player;
Entity house1;
const int BG_FAR_AWAY_CNT = 10;
Entity bgFarAway[BG_FAR_AWAY_CNT];


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

void updateBackground(float dt)
{
    // Move Background
    for (int i = 0; i < BG_FAR_AWAY_CNT; i++)
    {
        bgFarAway[i].moveBuffered(-10 * dt, 0);
        // Check if background is out of screen
        /*
        if (bgFarAway[i].getPosition().x < 0 + bgFarAway[i].getSpriteWidth())
        {

        }
        */
    }
    // Clean up

}

void update()
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
    updateBackground(dt);

}

void draw()
{
    arduboy.clear();
    
    // Draw background
    for (int i = 0; i < BG_FAR_AWAY_CNT; i++)
    {
        bgFarAway[i].draw(arduboy);
    }
    house1.draw(arduboy);
    player.draw(arduboy);
    // Draw Fps
    arduboy.setCursor(0, 0);
    arduboy.print("FPS: ");
    arduboy.print(averageFpsPerSec);
    
    arduboy.display();

}

void setup()
{
    arduboy.begin();
    arduboy.initRandomSeed();
    arduboy.clear();
      
    player.setSprite(ImageData::PLAYER_SPRITE, ImageData::PLAYER_SPRITE_WIDTH, 
        ImageData::PLAYER_SPRITE_HEIGHT);
    house1.setSprite(ImageData::BG_HOUSE_1_SPRITE, ImageData::BG_HOUSE_1_SPRITE_WIDTH, 
        ImageData::BG_HOUSE_1_SPRITE_HEIGHT);
    house1.setPosition(0, SCREEN_HEIGHT - ImageData::BG_HOUSE_1_SPRITE_HEIGHT);
    
    
    for (int i = 0; i < BG_FAR_AWAY_CNT; i++)
    {
        int posX = random(0, SCREEN_WIDTH + 1);
        int posY = random(0, SCREEN_HEIGHT + 1);
        bgFarAway[i].setPosition(posX, posY);
        bgFarAway[i].setSprite(ImageData::BG_STAR_VERY_FAR_SPRITE, 
            ImageData::BG_STAR_VERY_FAR_SPRITE_WIDTH, 
            ImageData::BG_STAR_VERY_FAR_SPRITE_HEIGHT
        );
    }

    timeStampLast = millis();
}

void loop()
{
    update();
    draw();
}
