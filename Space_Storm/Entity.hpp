#pragma once
#include <Arduboy2.h>
#include "Vector2.hpp"


class Entity
{
private:
    unsigned char* m_sprite;
    byte m_spriteWidth;
    byte m_spriteHeight;

    Vector2 m_pos;
    float m_movementBufferX;
    float m_movementBufferY;

public:
    Entity();

    void setSprite(unsigned char* sprite, byte spriteWidth, byte spriteHeight);

    Vector2 getPosition();
    void setPosition(byte posX, byte posY);
    
    byte getSpriteWidth();
    byte getSpriteHeight();

    void move(byte x, byte y);
    // Remember the movement and only moves when a full step is full. When movement is more
    // then a full step the rest is buffered
    void Entity::moveBuffered(float x, float y);
    
    virtual void update(float dt);
    virtual void draw(const Arduboy2 &arduboy);
};
