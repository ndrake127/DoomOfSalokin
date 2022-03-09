#include "InputSystem.h"

#include "components.h"

#include <iostream>

InputSystem::InputSystem() {
    w = 0;
    a = 0;
    s = 0;
    d = 0;
}

// instead of directly modifying velocity,
// create a struct with flags for the player

void InputSystem::Update(entt::registry& registry) {
    auto PlayerView = registry.view<Player, Actions>();

    PlayerView.each([this](auto&& player, auto&& actions) {
        actions.MoveHorizontal = Horizontal();

        if(actions.MoveHorizontal != 0) {
            if(actions.MoveHorizontal == -1) actions.lookingLeft = true;
            else                             actions.lookingLeft = false;
        }
        
        if(Vertical() == -1) actions.Jump = true;
        else                 actions.Jump = false;
    });
}

void InputSystem::RegisterKeyPress(sf::Event& event) {
    switch(event.key.code) {
        case sf::Keyboard::W:
            w = 1;
            break;

        case sf::Keyboard::A:
            a = 1;
            break;

        case sf::Keyboard::S:
            s = 1;
            break;

        case sf::Keyboard::D:
            d = 1;
            break;
    }
}

void InputSystem::RegisterKeyRelease(sf::Event& event) {
    switch(event.key.code) {
        case sf::Keyboard::W:
            w = 0;
            break;

        case sf::Keyboard::A:
            a = 0;
            break;

        case sf::Keyboard::S:
            s = 0;
            break;

        case sf::Keyboard::D:
            d = 0;
            break;
    }
}

int InputSystem::Horizontal() {
    if(a) {
        if(d) return  0;
        else  return -1;
    } else {
        if(d) return  1;
        else  return  0;
    }
}

int InputSystem::Vertical() {
    if(w) {
        if(s) return  0;
        else  return -1;
    } else {
        if(s) return  1;
        else  return  0;
    }
}