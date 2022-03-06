#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "components.h"

class PhysicsSystem {
public:
    void Update(entt::registry& registry, float dt);
};