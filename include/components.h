#pragma once

#include <SFML/Graphics.hpp>

struct Player {};

struct Collision {
    bool Up = false;
    bool Down = true;
    bool Left = false;
    bool Right = false;
};

struct Actions {
    int MoveHorizontal = 0;
    bool Jump = false;
};

struct Drawable {
    sf::Sprite mSprite;
    bool draw = true;
};

struct Physics {
    float x, y;
    float dx, dy;
    float ax, ay;
    float m;
};