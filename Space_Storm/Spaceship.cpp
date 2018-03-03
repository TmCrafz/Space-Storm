#include "Spaceship.hpp"

Spaceship::Spaceship()
: m_hp{10}
{

}

void Spaceship::setHp(int hp)
{
    m_hp = hp;
}
int Spaceship::getHp() const
{
    return m_hp;
}
