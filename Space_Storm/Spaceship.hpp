#pragma once
#include "Entity.hpp"
#include "Projectile.hpp"

class Spaceship : public Entity 
{
private:
    static const byte MAX_PROJECTILE_CNT = 5;
    
    // Types: 0 - Player, 1 - Enemy^
    byte m_type;
    unsigned int m_hp;
    
    Projectile m_projectiles[MAX_PROJECTILE_CNT];
    byte m_projectileArrPos;
    // Timeout in seconds
    byte m_projectileTimeout;
    float m_timeoutTime;
public:
    Spaceship();
    
    void setType(byte type);
    byte getType() const;

    void setHp(int hp);
    int getHp() const;
    
    void addProjectile();
    void clearProjectiles();
    // Automatic movement for KI stuff
    void moveAutomatic();

    virtual void update(float dt) override;
    virtual void draw(const Arduboy2 &arduboy) override;
};
