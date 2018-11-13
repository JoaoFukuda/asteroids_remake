/*
    Sargittarius 2 - Game about arrows and weird laws of gravity
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

#define WINDOW_WIDTH 150
#define WINDOW_HEIGHT 150

#include <SFML/Graphics.hpp>

#include <math.h>
#define PI 3.14

class Ship
{
private:
    sf::ConvexShape shape;

    int width, height;
public:
    sf::View view;

    float rotation, scale;
    sf::Vector2f position;
    sf::Vector2f velocity;

    Ship(int x, int y);

    bool Update();
    sf::ConvexShape Draw(sf::RenderWindow *window);
};
