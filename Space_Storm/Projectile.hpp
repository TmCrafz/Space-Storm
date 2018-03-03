#pragma once
#include "Entity.hpp"


class Projectile : public Entity 
{
private:
    byte m_damage;
    byte m_velocity;
    bool m_isActive;
public:
    Projectile();

    void setDamage(byte damage);
    byte getDamage() const;

    void setVelocity(byte velocity);
    byte getVelocity() const;
    
    void setIsActive(bool isActive);
    bool isActive() const;

    virtual void update(float dt) override;
};
