#include "pipe.hpp"
#include "random.hpp"
#include "program.hpp"

bool Pipe::initialize(){
    if(!texture.loadFromFile("media/sprites/pipe.png")){
        return false;
    }

    upperHitbox.setSize(size);
    lowerHitbox.setSize(size);
    //Set the origin to the bottom-left corner
    upperHitbox.setOrigin(upperHitbox.getPoint(3));

    //Scale the sprites to match the hitbox
    sf::Vector2f spriteScale = {2.9, 2.9};
    upperSprite.setScale(spriteScale);
    lowerSprite.setScale(spriteScale);

    upperSprite.setTexture(texture);
    lowerSprite.setTexture(texture);

    //Rotate the pipe so that the opening is facing down
    upperSprite.rotate(180);
    //Set the origin to the bottom-left corner
    upperSprite.setOrigin(upperSprite.getLocalBounds().width, 0);

    reset();

    return true;
}

void Pipe::reset(){
    float x = Program::getWindowSize().x + 50;
    float upperY = (float)Random::rand_int(100, 500);
    upperHitbox.setPosition(x, upperY);

    float space = (float)Random::rand_int(200, 400);
    float lowerY = upperY + space;

    lowerHitbox.setPosition(x, lowerY);

    hasPassedBird = false;
}

void Pipe::onPassBird(){
    hasPassedBird = true;
}

void Pipe::update(){
    upperHitbox.move(-moveSpeed * Program::getFrameTime().asSeconds(), 0);
    lowerHitbox.setPosition(upperHitbox.getPosition().x, lowerHitbox.getPosition().y);

    upperSprite.setPosition(upperHitbox.getPosition());
    lowerSprite.setPosition(lowerHitbox.getPosition());

    //Pipes are off the screen
    if(upperHitbox.getPosition().x + upperHitbox.getSize().x < -50){
        reset();
    }
}

void Pipe::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(upperSprite, states);
    target.draw(lowerSprite, states);
}

sf::RectangleShape& Pipe::getUpperHitbox(){
    return upperHitbox;
}
sf::RectangleShape& Pipe::getLowerHitbox(){
    return lowerHitbox;
}
bool Pipe::getHasPassedBird(){
    return hasPassedBird;
}