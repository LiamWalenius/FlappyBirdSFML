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
    gameOverText.setPosition(getPosition().x, getPosition().y - panelSize/2 + 20);

    initializeText(scoreText, "Your score: 15", 30);
    scoreText.setPosition(getPosition().x, gameOverText.getPosition().y + 100);

    initializeText(restartText, "Press 'r' to restart", 30);
    restartText.setPosition(getPosition().x, scoreText.getPosition().y + 100);

    initializeText(exitText, "Press 'x' to exit", 30);
    exitText.setPosition(getPosition().x, restartText.getPosition().y + 100);

    return true;
}

void EndMenu::update(){
    panel.setPosition(getPosition());

}

void EndMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(panel);
    target.draw(gameOverText);
    target.draw(scoreText);
    target.draw(restartText);
    target.draw(exitText);
}