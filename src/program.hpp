#pragma once

#include <SFML/Graphics.hpp>

namespace Program{

bool initialize();
void startMainLoop();
void exitProgram();

sf::Font& getImpactFont();
sf::Vector2u getWindowSize();

}