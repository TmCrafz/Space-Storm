#include "Spaceship.hpp"
#include "ImageData.hpp"
#include "Globals.hpp"

Spaceship::Spaceship()
: m_type{0}
, m_hp{10}
, m_projectileArrPos{0}
, m_projectileTimeout{1}
, m_timeoutTime(m_projectileTimeout)
{

}

void Spaceship::setType(byte type)
{
    m_type = type;
}

byte Spaceship::getType() const
{
    return m_type;
}

void Spaceship::setHp(int hp)
{
    m_hp = hp;
}

int Spaceship::getHp() const
{
    return m_hp;
}

void Spaceship::spawnProjectile()
{
    // Only spawn projectile if timeout is over
    if (m_timeoutTime < m_projectileTimeout)
    {
        return;
    }
    m_timeoutTime = 0.f;
    m_projectiles[m_projectileArrPos].
        setSprite(
            ImageData::PLAYER_PROJECTILE_DEFAULT, 
            ImageData::PLAYER_PROJECTILE_DEFAULT_WIDTH, 
            ImageData::PLAYER_PROJECTILE_DEFAULT_HEIGHT
    );
    m_projectiles[m_projectileArrPos].setDamage(1);
    m_projectiles[m_projectileArrPos].setIsActive(true);
    m_projectiles[m_projectileArrPos].setPosition(
        getPosition().x + getSpriteWidth() / 2 + 1,
        getPosition().y + getSpriteHeight() / 2
    );
    switch(m_type)
    {
        case 0: m_projectiles[m_projectileArrPos].setVelocity(16); break;
        case 1: m_projectiles[m_projectileArrPos].setVelocity(-16); break;
    }
    m_projectileArrPos++;
    if (m_projectileArrPos > MAX_PROJECTILE_CNT - 1)
    {
        m_projectileArrPos = 0;
    }        
}

void Spaceship::clearProjectiles()
{
    for (byte i = 0; i < MAX_PROJECTILE_CNT; i++)
    {
        if (!m_projectiles[i].isActive()) {
            continue;
        }
        Vector2 projectilePos = m_projectiles[i].getPosition();
        // Deactivate projectile when its outside of screen
        if (projectilePos.x < 0 || projectilePos.x > Globals::SCREEN_WIDTH ||
            projectilePos.y < 0 || projectilePos.y > Globals::SCREEN_HEIGHT)
        {
            m_projectiles[i].setIsActive(false);
        }
    }

}

void Spaceship::moveAutomatic(float dt)
{
    if (m_type == 0)
    {
        return;
    }
    else if (m_type == 1)
    {
        spawnProjectile();
    }
}

void Spaceship::update(float dt)
{
    Entity::update(dt);
    m_timeoutTime += dt;
    moveAutomatic(dt);
    for (byte i = 0; i < MAX_PROJECTILE_CNT; i++)
    {
        if (!m_projectiles[i].isActive()) {
            continue;
        }
        m_projectiles[i].update(dt);
    }
    clearProjectiles();
}

void Spaceship::draw(const Arduboy2 &arduboy)
{
    Entity::draw(arduboy);
    for (byte i = 0; i < MAX_PROJECTILE_CNT; i++)
    {
        if (!m_projectiles[i].isActive()) {
            continue;
        }
        m_projectiles[i].draw(arduboy);
    }
}
