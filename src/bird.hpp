#pragma once

#include <SFML/Graphics.hpp>

class Bird : public sf::Drawable{
    public:
        bool initialize();
        void reset();

        void jump();

        void update();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        sf::RectangleShape& getHitbox();

    private:
        const float jumpSpeed = 4;

        //Speed will only ever be in the y direction, x position is fixed
        float speed;

        sf::RectangleShape hitbox;
        sf::Texture texture;
        sf::Sprite sprite;
};