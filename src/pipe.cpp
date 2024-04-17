#include "pipe.hpp"
#include "random.hpp"

bool Pipe::initialize(){
    if(!texture.loadFromFile("media/sprites/pipe.png")){
        return false;
    }
    sf::Vector2f spriteScale = {2.9, 2};
    upperSprite.setTexture(texture);
    upperSprite.setScale(spriteScale);
    lowerSprite.setTexture(texture);
    lowerSprite.setScale(spriteScale);

    upperHitbox.setSize(size);
    upperHitbox.setFillColor({255, 0, 0, 100});
    lowerHitbox.setSize(size);
    lowerHitbox.setFillColor({255, 0, 0, 100});

    reset();

    return true;
}

void Pipe::reset(){
    float x = 900;
    float upperY = (float)Random::rand_int(100, 500) - size.y;
    upperHitbox.setPosition(x, upperY);

    float space = (float)Random::rand_int(200, 400);
    float lowerY = upperY + size.y + space;

    lowerHitbox.setPosition(x, lowerY);

    hasPassedBird = false;
}

void Pipe::onPassBird(){
    hasPassedBird = true;
}

void Pipe::update(){
    upperHitbox.move(-speed, 0);
    lowerHitbox.move(-speed, 0);

    upperSprite.setPosition(upperHitbox.getPosition());
    lowerSprite.setPosition(lowerHitbox.getPosition());

    //Pipes are off the screen
    if(upperHitbox.getPosition().x < -150){
        reset();
    }
}

void Pipe::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(upperSprite);
    target.draw(upperHitbox);
    target.draw(lowerSprite);
    target.draw(lowerHitbox);
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