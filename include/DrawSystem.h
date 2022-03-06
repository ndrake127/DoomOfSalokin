#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

class DrawSystem {
public:
    DrawSystem(sf::RenderWindow*);

    void Update(entt::registry& registry);
    
private:
    sf::RenderWindow * const mWindow;
};