#include "PhysicsSystem.h"

#include <iostream>

void PhysicsSystem::Update(entt::registry& registry, float dt) {
    auto PositionDrawableView = registry.view<Physics, Drawable>();
    auto PhysicsView = registry.view<Physics, Actions, Collision>();
    
    float mult = 3.0f;

    float gravity = 100.0f * mult;

    PhysicsView.each([dt, gravity, mult](auto&& phys, auto&& actions, auto&& collision){
        if(collision.Down) {
            if(actions.Jump) {                                          // Jump only if on ground
                phys.dy += -100.0f * mult;
                collision.Down = false;
            }

            if(actions.MoveHorizontal) {
                phys.ax = actions.MoveHorizontal * 200.0f * mult;       // Set acceleration to move
            } else {
                if(phys.dx > -30.0f && phys.dx < 30.0f) {               // When not moving, accelerate massively in reverse direction
                    phys.ax = 0;
                    phys.dx = 0;
                } else {
                    phys.ax = 1000 * -phys.dx * dt;
                }
            }
        } else {
            phys.ax = 0.0f;                                             // If in air, no horizontal acceleration
        }

        if(phys.dx < -100.0f * mult) {                                  // Cap velocity
            phys.dx = -100.0f * mult;
            phys.ax = 0;
        } else if(phys.dx > 100.0f * mult) {
            phys.dx = 100.0f * mult;
            phys.ax = 0;
        }

        phys.dx += phys.ax * dt;                                        // Calculate velocity
        phys.dy += (gravity + phys.ay) * dt;
        
        phys.x += phys.dx * dt;                                         // Calculate position
        phys.y += phys.dy * dt;     

        if(phys.y >= 500.0) {                                           // Detect ground collision - temporary
            phys.y = 500.0;
            phys.dy = 0.0;
            collision.Down = true;
        }
    });

    // Update Sprite Position
    PositionDrawableView.each([](auto&& phys, auto&& drawable){
        drawable.mSprite.setPosition(phys.x, phys.y);
    });
}
