#include "Entity.hpp"

Entity::Entity()
: m_sprite{nullptr}
, m_pos{0, 0}
, m_spriteWidth{0}
, m_spriteHeight{0}
{

}

void Entity::setSprite(unsigned char* sprite, unsigned spriteWidth, unsigned spriteHeight)
{
    m_sprite = sprite;
    m_spriteWidth = spriteWidth;
    m_spriteHeight = spriteHeight;
}

Vector2 Entity::getPosition()
{
    return m_pos;
}

void Entity::setPosition(int posX, int posY)
{
    m_pos.x = posX;
    m_pos.y = posY;
}

void Entity::draw(const Arduboy2 &arduboy)
{
    // params: posX, posY, image, width, height, COLOR 
    // (When white, all white pixels are drawn white)
    arduboy.drawBitmap(m_pos.x, m_pos.y, m_sprite, m_spriteWidth, m_spriteHeight);
}
