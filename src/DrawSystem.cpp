#include "DrawSystem.h"

#include "components.h"

#include <iostream>

DrawSystem::DrawSystem(sf::RenderWindow *win, ResourceManager *res) : mWindow(win), mResourceManager(res) {};

void DrawSystem::Update(entt::registry& registry) {
    mWindow->clear();
    
    auto ActionView = registry.view<Drawable, Actions>();
    auto AnimationView = registry.view<Drawable, TimeAnimation>();
    auto DrawableView = registry.view<Drawable>();

    ActionView.each([this](auto&& drawable, auto&& actions){
        drawable.mSprite.setOrigin(drawable.mSprite.getTexture()->getSize().x / 2, 0.0f);
        
        if(actions.lookingLeft) drawable.mSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
        else                    drawable.mSprite.setScale(sf::Vector2f(1.0f, 1.0f));
    });

    AnimationView.each([this](auto&& drawable, auto&& animation){
        unsigned reducedTime = mClock.getElapsedTime().asSeconds() * 2;
        reducedTime %= animation.textureID.size();      // calculate index in textureID for current texture

        drawable.mSprite.setTexture(mResourceManager->getTexture(animation.textureID[reducedTime]));
    });

    DrawableView.each([this](auto&& drawable) {
        if(drawable.draw) mWindow->draw(drawable.mSprite);
    });

    mWindow->display();
}