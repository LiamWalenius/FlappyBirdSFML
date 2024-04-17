#pragma once

#include <SFML/Graphics.hpp>
#include "bird.hpp"
#include "pipe.hpp"
#include "endmenu.hpp"

class Game : public sf::Drawable{
    enum class State{Game, End};

    public:
        bool initialize();
        void restart();

        void onKeyPressed(sf::Keyboard::Key);

        void update();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        bool birdIsColliding();
        void endGame();

        void updateGame();
        void updateEnd();

        void incrementScore();
        void updateScoreText();

        Bird bird;
        Pipe pipe;
        sf::RectangleShape ground;
        int score;
        State state;
        sf::Text scoreText;
        EndMenu endMenu;
};