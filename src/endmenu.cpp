#include "endmenu.hpp"
#include "program.hpp"

void initializeText(sf::Text& text, sf::String str, int size){
    text.setString(str);
    text.setFont(Program::getImpactFont());
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3);
    text.setOrigin(text.getLocalBounds().width / 2, 0);
}

bool EndMenu::initialize(){
    float panelSize = Program::getWindowSize().x * 0.75;
    panel.setSize({panelSize, panelSize});
    panel.setOrigin(panelSize / 2, panelSize / 2);
    panel.setFillColor({255, 227, 143});

    setPosition(Program::getWindowSize().x / 2, Program::getWindowSize().y / 2);

    initializeText(gameOverText, "Game Over!", 50);
    initializeText(scoreText, "Your score: 0", 30);
    initializeText(restartText, "Press 'r' to restart", 30);
    initializeText(exitText, "Press 'x' to exit", 30);

    updatePositions();

    return true;
}

void EndMenu::updatePositions(){
    panel.setPosition(getPosition());

    gameOverText.setPosition(getPosition().x, getPosition().y - panel.getSize().y/2 + 40);
    scoreText.setPosition(getPosition().x, gameOverText.getPosition().y + 100);
    restartText.setPosition(getPosition().x, scoreText.getPosition().y + 100);
    exitText.setPosition(getPosition().x, restartText.getPosition().y + 100);
}

void EndMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(panel);
    target.draw(gameOverText);
    target.draw(scoreText);
    target.draw(restartText);
    target.draw(exitText);
}

void EndMenu::setScore(int score){
    scoreText.setString("Your score: " + std::to_string(score));
}