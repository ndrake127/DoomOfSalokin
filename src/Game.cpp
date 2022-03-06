#include "Game.h"
#include "components.h"

#include <iostream>

Game::Game() {
    mWindow.create(sf::VideoMode(mWindowWidth, mWindowHeight), mWindowTitle);

    mEntity = mEntityRegistry.create();
    
    Drawable& test = mEntityRegistry.emplace<Drawable>(mEntity);
    mEntityRegistry.emplace<Player>(mEntity);
    mEntityRegistry.emplace<Physics>(mEntity, 75.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    mEntityRegistry.emplace<Actions>(mEntity);
    mEntityRegistry.emplace<Collision>(mEntity);

    if (!texture2.loadFromFile("resources/background.jpg")) {
        std::cerr << "Background image not loaded!\n";
    }

    if (!texture.loadFromFile("resources/gandalf.png")) {
        std::cerr << "Gandalf not loaded!\n";
    }

    test.mSprite.setTexture(texture);
    test.mSprite.scale(sf::Vector2f(1.0f, 1.0f) * 3.0f);

    mEntity = mEntityRegistry.create();
    
    Drawable& test2 = mEntityRegistry.emplace<Drawable>(mEntity);
    test2.mSprite.setTexture(texture2);

    mDrawSystem.reset(new DrawSystem(&mWindow));
    mInputSystem.reset(new InputSystem);
}

Game::~Game() {}

void Game::Begin() {        
    //  sf::Clock absoluteClock;
    sf::Clock clock;

    while(mWindow.isOpen()) {
        // std::cout << "Loop Rate: " << 1.0 / absoluteClock.getElapsedTime().asSeconds() << '\n';
        // absoluteClock.restart();
        
        sf::Event event;

        while (mWindow.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    mWindow.close();
                    break;

                case sf::Event::KeyPressed:
                    mInputSystem->RegisterKeyPress(event);
                    break;

                case sf::Event::KeyReleased:
                    mInputSystem->RegisterKeyRelease(event);
                    break;
            }
        }

        if(clock.getElapsedTime().asSeconds() >= mFrameTime) {
            float dt = clock.getElapsedTime().asSeconds();
            
            Update(dt);
            Render();

            clock.restart();
        }
    }
}

void Game::Update(float dt) {
    mInputSystem->Update(mEntityRegistry);
    mPhysicsSystem->Update(mEntityRegistry, dt);
}

void Game::Render() {
    mDrawSystem->Update(mEntityRegistry);
}