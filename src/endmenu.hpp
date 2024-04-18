#pragma once

#include <SFML/Graphics.hpp>

class EndMenu : public sf::Drawable, public sf::Transformable{
    public:
        bool initialize();

        void updatePositions();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void setScore(int score);
        void setHighScore(int score);

    private:
        sf::RectangleShape panel;
        sf::Text gameOverText;
        sf::Text scoreText;
        sf::Text highScoreText;
        sf::Text restartText;
        sf::Text exitText;
};
