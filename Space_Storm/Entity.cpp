#include "Entity.hpp"

Enitiy::Entity()
: m_pos{0, 0}
{

}

Vector2 Entity::getPosition()
{
    return m_pos;
}

Vector2 Entity::setPosition(int posX, int posY)
{
    m_pos.x = posX;
    m_pos.y = posY;
}
