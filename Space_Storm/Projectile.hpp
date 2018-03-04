#pragma once
#include "Entity.hpp"


class Projectile : public Entity 
{
private:
    byte m_damage;
    char m_velocity;
public:
    Projectile();

    void setDamage(byte damage);
    byte getDamage() const;

    void setVelocity(char velocity);
    char getVelocity() const;
    
    virtual void update(float dt) override;
};
