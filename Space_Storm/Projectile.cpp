#include "Projectile.hpp"

Projectile::Projectile()
: m_damage{0}
, m_velocity{0}
, m_isActive{false}
{
    
}

void Projectile::setDamage(unsigned int damage)
{
    m_damage = damage;
}

int Projectile::getDamage() const
{
    return m_damage;
}

void Projectile::setVelocity(int velocity)
{
    m_velocity = velocity;
}

int Projectile::getVelocity() const
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
