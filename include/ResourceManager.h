#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

class ResourceManager {
public:
    int loadTexture(std::string path);
    const sf::Texture& getTexture(int tID) const;

private:
    std::vector<sf::Texture *> mTextures;
};