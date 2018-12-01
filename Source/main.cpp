/*
    Asteroids Remake - Asteroids with multiplayer and dynamic windows
    Copyright (C) 2018 - João Francisco Cocca Fukuda

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    If in any doubts, contact me at <joao.fukuda@usp.br>
 */

#define SFML_STATIC

#include <SFML/Window.hpp>
#include "object.hpp"

int main()
{
    sf::VideoMode desktopWindowMode = sf::VideoMode::getDesktopMode();
    unsigned int DESKTOP_WIDTH, DESKTOP_HEIGHT;
    DESKTOP_WIDTH = desktopWindowMode.width;
    DESKTOP_HEIGHT = desktopWindowMode.height;

    Ship ship(DESKTOP_WIDTH, DESKTOP_HEIGHT);

    //TODO: Make the main loop through the score window (not yet implemented)

    //If operational system is unix, then promot this
    #ifdef __unix__
    std::cout << "Are you using multiple monitors? (y/n)";
    char a;
    std::cin >> a;
    if(a == 'y')
    {
        std::cout << "Place the mouse at the top left corner of your screen, then press enter to continue ...";
        std::cin.get();
        ship.setMonitorOffset(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    }
    #endif

    while(ship.isOpen())
    {
        ship.InputHandler();
        ship.Update();
        ship.Draw();
    }

    return 0;
}
