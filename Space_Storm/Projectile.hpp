#pragma once
#include "Entity.hpp"


class Projectile : public Entity 
{
private:
    unsigned int m_damage;
    int m_velocity;
    bool m_isActive;
public:
    Projectile();

    void setDamage(unsigned int damage);
    int getDamage() const;

    void setVelocity(int velocity);
    int getVelocity() const;
    
    void setIsActive(bool isActive);
    bool isActive() const;
};
