#pragma once
#include "Entity.hpp"
#include "Projectile.hpp"

class Spaceship : public Entity 
{
private:
    unsigned int m_hp;
    
    static const int MAX_PROJECTILE_CNT = 10;
    Projectile projectiles[MAX_PROJECTILE_CNT];
    int playerProjectileArrPos = 0;

public:
    Spaceship();

    void setHp(int hp);
    int getHp() const;
};
