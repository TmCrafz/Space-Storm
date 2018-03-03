#include "Spaceship.hpp"
#include "ImageData.hpp"

Spaceship::Spaceship()
: m_hp{10}
, m_projectileArrPos{0}
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

void Spaceship::addProjectile()
{
    m_projectiles[m_projectileArrPos].
        setSprite(
            ImageData::PLAYER_PROJECTILE_DEFAULT, 
            ImageData::PLAYER_PROJECTILE_DEFAULT_WIDTH, 
            ImageData::PLAYER_PROJECTILE_DEFAULT_HEIGHT
    );
    m_projectiles[m_projectileArrPos].setDamage(1);
    m_projectiles[m_projectileArrPos].setVelocity(3);
    m_projectiles[m_projectileArrPos].setIsActive(true);
    m_projectiles[m_projectileArrPos].setPosition(
        getPosition().x + getSpriteWidth() / 2 + 1,
        getPosition().y + getSpriteHeight() / 2
    );
    m_projectileArrPos++;
    if (m_projectileArrPos > MAX_PROJECTILE_CNT - 1)
    {
        m_projectileArrPos = 0;
    }        
}

void Spaceship::draw(const Arduboy2 &arduboy)
{
    Entity::draw(arduboy);
    for (int i = 0; i < MAX_PROJECTILE_CNT; i++)
    {
        if (!m_projectiles[i].isActive()) {
            continue;
        }
        m_projectiles[i].draw(arduboy);
    }
}
