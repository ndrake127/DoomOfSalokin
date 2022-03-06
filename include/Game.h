#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "DrawSystem.h"
#include "PhysicsSystem.h"
#include "InputSystem.h"

class Game {
public:
    Game();
    ~Game();
    
    void Begin();

private:
    entt::entity                    mEntity;
    sf::Texture                     texture;

    void Update(float dt);                                                  // Called from begin
    void Render();                                                          // Called from begin

    sf::RenderWindow                mWindow;                                // Window and window information
    std::string                     mWindowTitle = "Doom Of Salokin";
    uint                            mWindowWidth = 1920;
    uint                            mWindowHeight = 1080;

    const float                     mFrameTime = 1.0 / 144.0;

    entt::registry                  mEntityRegistry;                        // ECS registry

    /* System Declarations */
    std::unique_ptr<DrawSystem>     mDrawSystem;                            // Handles entity drawing
    std::unique_ptr<PhysicsSystem>  mPhysicsSystem;                         // Handles entity movement
    std::unique_ptr<InputSystem>    mInputSystem;                           // Handles keyboard control
};