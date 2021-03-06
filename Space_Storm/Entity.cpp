#include "Entity.hpp"

Entity::Entity()
: m_sprite{nullptr}
, m_pos{0, 0}
, m_spriteWidth{0}
, m_spriteHeight{0}
, m_isActive{false}
{

}

void Entity::setSprite(unsigned char* sprite, byte spriteWidth, byte spriteHeight)
{
    m_sprite = sprite;
    m_spriteWidth = spriteWidth;
    m_spriteHeight = spriteHeight;
}

Vector2 Entity::getPosition()
{
    return m_pos;
}

void Entity::setPosition(byte posX, byte posY)
{
    m_pos.x = posX;
    m_pos.y = posY;
}

byte Entity::getSpriteWidth()
{
    return m_spriteWidth;
}

byte Entity::getSpriteHeight()
{
    return m_spriteHeight;
}

bool Entity::isActive() const
{
    return m_isActive;
}

void Entity::setIsActive(bool isActive)
{
    m_isActive = isActive;
}

void Entity::move(byte x, byte y)
{
    m_pos.x += x;
    m_pos.y += y;
}

void Entity::moveBuffered(float x, float y)
{
    m_movementBufferX += x;
    m_movementBufferY += y;
    byte movemenntX = (byte) m_movementBufferX;
    // Only move when there is min one step full
    if (abs(movemenntX) >= 1)
    { 
        // Move full step
        move(movemenntX, 0);
        // Store rest in buffer
        m_movementBufferX = m_movementBufferX - movemenntX;
    }
    byte movemenntY = (byte) m_movementBufferX;
    if (abs(movemenntY) >= 1)
    { 
        move(movemenntY, 0);
        m_movementBufferY = m_movementBufferY - movemenntX;
    }
}

void Entity::update(float dt)
{
    if (!isActive())
    {
        return false;
    }
}

void Entity::draw(const Arduboy2 &arduboy)
{
    if (!isActive())
    {
        return false;
    }
    // params: posX, posY, image, width, height, COLOR 
    // (When white, all white pixels are drawn white)
    arduboy.drawBitmap(m_pos.x, m_pos.y, m_sprite, m_spriteWidth, m_spriteHeight);
}
