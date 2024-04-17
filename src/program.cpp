#include "program.hpp"
#include "game.hpp"

sf::RenderWindow window(
        {600, 1000},
        "Flappy Bird",
        sf::Style::Titlebar | sf::Style::Close
);
Game game;
sf::Clock gameClock;
sf::Font impactFont;
bool running;

bool Program::initialize(){
    if(!impactFont.loadFromFile(R"(media\fonts\impact.ttf)")){
        return false;
    }

    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    if(!game.initialize()){
        return false;
    }

    running = true;

    return true;
}

void Program::startMainLoop(){
    while(running){
        for(auto event = sf::Event{}; window.pollEvent(event);){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    game.onKeyPressed(event.key.code);
                    break;

                default:
                    break;
            }
        }

        game.update();
        gameClock.restart();

        window.clear(sf::Color::Cyan);
        window.draw(game);
        window.display();
    }
}

void Program::exitProgram(){
    running = false;
}

sf::Font &Program::getImpactFont(){
    return impactFont;
}

sf::Vector2u Program::getWindowSize(){
    return window.getSize();
}

sf::Time Program::getFrameTime(){
    return gameClock.getElapsedTime();
}