#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "ResourceManager.h"

class DrawSystem {
public:
    DrawSystem(sf::RenderWindow *, ResourceManager *);

    void Update(entt::registry& registry);
    
private:
    sf::Clock                mClock;
    sf::RenderWindow * const mWindow;

    ResourceManager        * mResourceManager;
};