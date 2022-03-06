#include "DrawSystem.h"

#include "components.h"

DrawSystem::DrawSystem(sf::RenderWindow *win) : mWindow(win) {};

void DrawSystem::Update(entt::registry& registry) {
    mWindow->clear();
    
    auto DrawableView = registry.view<Drawable>();

    DrawableView.each([this](auto&& drawable) {
        if(drawable.draw) mWindow->draw(drawable.mSprite);
    });

    mWindow->display();
}