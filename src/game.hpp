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

        void onKeyPressed(sf::Keyboard::Key key);

        void update();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void onExitProgram();

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
        int highScore;
        State state;
        sf::Text scoreText;
        EndMenu endMenu;
};