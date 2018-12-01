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

    while(ship.isOpen())
    {
        ship.InputHandler();
        ship.Update();
        ship.Draw();
    }

    std::cout << "Press enter to continue ...";
    std::cin.get();

    return 0;
}
