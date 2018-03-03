#pragma once
#include "Entity.hpp"
#include "Projectile.hpp"

class Spaceship : public Entity 
{
private:
    unsigned int m_hp;
    
    static const byte MAX_PROJECTILE_CNT = 10;
    Projectile m_projectiles[MAX_PROJECTILE_CNT];
    byte m_projectileArrPos;
    // Timeout in seconds
    byte m_projectileTimeout;
    float m_timeoutTime;
public:
    Spaceship();

    void setHp(int hp);
    int getHp() const;
    void addProjectile();
    
    virtual void update(float dt) override;
    virtual void draw(const Arduboy2 &arduboy) override;
};
