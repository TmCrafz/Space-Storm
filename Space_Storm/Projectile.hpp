#pragma once
#include "Entity.hpp"


class Projectile : public Entity 
{
private:
    unsigned int m_damage;
    int m_velocity;

public:
    Projectile(unsigned int damage, int velocity);

    void setDamage(unsigned int damage);
    int getDamage() const;

    void setVelocity(int velocity);
    int getVelocity() const;

};
