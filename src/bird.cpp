#include "bird.hpp"

#include <iostream>

bool Bird::initialize(){
    if(!texture.loadFromFile(R"(media\sprites\bird.png)")){
        return false;
    }
    sprite.setTexture(texture);
    sprite.setScale(1.5, 1.5);

    //Scale the hitbox to match the sprite
    hitbox.setSize({50, 40});
    reset();

    return true;
}

void Bird::reset(){
    speed = 0;
    hitbox.setPosition(30, 10);
}

void Bird::jump(){
    speed = jumpSpeed;
}

void Bird::update(sf::Time time){
    speed += -9.81f * time.asSeconds();
    hitbox.move(0, -speed);

    //Bird should bounce off the ceiling
    if(hitbox.getPosition().y < 0){
        hitbox.setPosition(hitbox.getPosition().x, 0);
        speed = 0;
    }

    sprite.setPosition(hitbox.getPosition());
}

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(sprite);
}

sf::RectangleShape& Bird::getHitbox(){
    return hitbox;
}