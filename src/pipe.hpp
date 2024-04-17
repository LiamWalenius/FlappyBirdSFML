#pragma once

#include <SFML/Graphics.hpp>

class Pipe : public sf::Drawable{
    public:
        bool initialize();
        void reset();

        void onPassBird();

        void update();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        sf::RectangleShape& getUpperHitbox();
        sf::RectangleShape& getLowerHitbox();
        bool getHasPassedBird();

    private:
        const sf::Vector2f size{150, 1000};
        const float moveSpeed = 300;

        sf::RectangleShape upperHitbox, lowerHitbox;
        bool hasPassedBird;

        sf::Texture texture;
        sf::Sprite upperSprite, lowerSprite;
};