#pragma once

#include <SFML/Graphics.hpp>

class EndMenu : public sf::Drawable, public sf::Transformable{
    public:
        bool initialize();

        void update();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        sf::RectangleShape panel;
        sf::Text gameOverText;
        sf::Text scoreText;
        sf::Text restartText;
        sf::Text exitText;
};
