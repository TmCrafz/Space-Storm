#pragma once
#include <Arduboy2.h>
#include "Vector2.hpp"


class Entity
{
private:
    unsigned char* m_sprite;
    unsigned int m_spriteWidth;
    unsigned int m_spriteHeight;

    Vector2 m_pos;

public:
    Entity();

    void setSprite(unsigned char* sprite, unsigned spriteWidth, unsigned spriteHeight);

    Vector2 getPosition();
    void setPosition(int posX, int posY);
    
    void move(int x, int y);

    void draw(const Arduboy2 &arduboy);
};
