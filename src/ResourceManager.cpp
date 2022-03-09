#include "ResourceManager.h"

#include <iostream>

int ResourceManager::loadTexture(std::string path) {
    sf::Texture *texture = new sf::Texture;
    
    mTextures.push_back(texture);

    if (!mTextures.back()->loadFromFile(path)) {
        std::cerr << "Texture at " << path << " not loaded!\n";
        delete mTextures.back();
        mTextures.pop_back();
        return -1;
    } else {;
        std::cout << "Textured at " << path << " loaded. ID: " << mTextures.size() - 1 << '\n';
        return mTextures.size() - 1;
    }
}

const sf::Texture& ResourceManager::getTexture(int tID) const {    
    if(tID >= 0 && tID < mTextures.size()) {
        return *mTextures[tID];
    } else {
        std::cerr << "Invalid texture ID " << tID << "! Returning first texture...\n";
        return *mTextures[0];
    }
}