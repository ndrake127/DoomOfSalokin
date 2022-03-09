#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Player {};

struct Collision {
    bool Up = false;
    bool Down = true;
    bool Left = false;
    bool Right = false;
};

struct Actions {
    int MoveHorizontal = 0;
    bool lookingLeft = false;
    bool Jump = false;
};

struct Drawable {
    sf::Sprite mSprite;
    bool horizontalFlip;
    bool draw = true;
};

struct Physics {
    float x, y;
    float dx, dy;
    float ax, ay;
    float m;
};

struct TimeAnimation {              // This component indicates to the draw manager that the sprite should periodically change texture
    std::vector<int> textureID;     // list of textureIDs to use to animate a sprite
    int period;                     // 0 means animation is disabled, 1 means swap every 1 rame, 2 means swap every 2 frames, etc
    bool random;                    // when true, order of textures when swapped is random
};