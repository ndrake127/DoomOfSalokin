#pragma once

#include <SFML/Window/Event.hpp>
#include <entt/entity/registry.hpp>

class InputSystem {
public:
    InputSystem();

    void Update(entt::registry& registry);

    void RegisterKeyPress(sf::Event& event);
    void RegisterKeyRelease(sf::Event& event);

private:
    int Horizontal();
    int Vertical();

    int w;
    int a;
    int s;
    int d;
};