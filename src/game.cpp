#include "game.hpp"
#include "program.hpp"
#include <fstream>

bool Game::initialize(){
    if(!bird.initialize() || !pipe.initialize() || !endMenu.initialize()){
        return false;
    }

    std::ifstream highScoreFile("highScore.txt");
    if(!highScoreFile.is_open()){
        highScore = 0;
    }
    else{
        highScoreFile>>highScore;

        highScoreFile.close();
    }

    scoreText.setFont(Program::getImpactFont());
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(3);

    ground.setSize({(float)Program::getWindowSize().x, 30});
    ground.setPosition(0, Program::getWindowSize().y - 30);
    ground.setFillColor({0, 100, 0});

    restart();

    return true;
}

void Game::restart(){
    score = 0;
    updateScoreText();
    state = State::Game;
    bird.reset();
    pipe.reset();
}

void Game::onKeyPressed(sf::Keyboard::Key key){
    switch(key){
        case sf::Keyboard::Space:
            bird.jump();
            break;

        default:
            break;
    }
}

void Game::update(){
    switch(state){
        case State::Game:
            return updateGame();

        case State::End:
            return updateEnd();
    }
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(bird, states);
    target.draw(pipe, states);
    target.draw(ground, states);

    switch(state){
        case State::Game:
            target.draw(scoreText, states);
            break;

        case State::End:
            target.draw(endMenu, states);
            break;
    }
}

bool Game::birdIsColliding(){
    auto birdBounds = bird.getHitbox().getGlobalBounds();

    return birdBounds.intersects(ground.getGlobalBounds())
        || birdBounds.intersects(pipe.getUpperHitbox().getGlobalBounds())
        || birdBounds.intersects(pipe.getLowerHitbox().getGlobalBounds());
}

void Game::endGame(){
    endMenu.setScore(score);
    if(score > highScore){
        highScore = score;
    }
    endMenu.setHighScore(highScore);

    state = State::End;
}

void Game::updateGame(){
    bird.update();
    pipe.update();

    if(birdIsColliding()){
        endGame();
    }

    if(
        !pipe.getHasPassedBird() &&
        bird.getHitbox().getPosition().x >= pipe.getUpperHitbox().getPosition().x + pipe.getUpperHitbox().getSize().x
    ){
        incrementScore();
    }
}

void Game::updateEnd(){
    endMenu.updatePositions();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
        return restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){
        Program::exitProgram();
    }
}

void Game::incrementScore(){
    score++;
    updateScoreText();

    pipe.onPassBird();
}

//Set the score text and move it to the center of the screen
void Game::updateScoreText(){
    scoreText.setString(std::to_string(score));
    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setOrigin(textRect.left + textRect.width/2, 0);
    scoreText.setPosition((float)Program::getWindowSize().x/2, 30);
}

void Game::onExitProgram(){
    std::ofstream highScoreFile("highScore.txt");
    if(!highScoreFile.is_open()){
        return;
    }

    highScoreFile<<highScore;

    highScoreFile.close();
}