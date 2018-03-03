#pragma once
#include "Entity.hpp"
#include "Projectile.hpp"

class Spaceship : public Entity 
{
private:
    unsigned int m_hp;
    
    static const int MAX_PROJECTILE_CNT = 10;
    Projectile m_projectiles[MAX_PROJECTILE_CNT];
    int m_projectileArrPos;

public:
    Spaceship();

    void setHp(int hp);
    int getHp() const;
    void addProjectile();
    
    virtual void draw(const Arduboy2 &arduboy) override;
};
