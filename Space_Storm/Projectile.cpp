#include "Projectile.hpp"

Projectile::Projectile()
: m_damage{0}
, m_velocity{0}
, m_isActive{false}
{
    
}

void Projectile::setDamage(byte damage)
{
    m_damage = damage;
}

byte Projectile::getDamage() const
{
    return m_damage;
}

void Projectile::setVelocity(byte velocity)
{
    m_velocity = velocity;
}

byte Projectile::getVelocity() const
{
    return m_velocity;
}

void Projectile::setIsActive(bool isActive)
{
    m_isActive = isActive;
}

bool Projectile::isActive() const
{
    return m_isActive;
}

void Projectile::update(float dt)
{
    Entity::update(dt);
    moveBuffered(m_velocity * dt, 0);

}
