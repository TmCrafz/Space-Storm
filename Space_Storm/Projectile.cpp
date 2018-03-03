#include "Projectile.hpp"

Projectile::Projectile(unsigned int damage, int velocity)
: m_damage{damage}
, m_velocity{velocity}
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
