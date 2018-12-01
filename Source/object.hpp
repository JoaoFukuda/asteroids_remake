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

#define WINDOW_WIDTH 150
#define WINDOW_HEIGHT 150

#include <iostream>
#include <SFML/Graphics.hpp>

#include <math.h>
#define PI 3.14

class Ship
{
    //TODO: Make a way to give every ship their unique id (1, 2, 3, ...)
private:
    sf::ConvexShape shape;      //The shape of the ship (i tried making a non-equilateral triangle)
    sf::RenderWindow window;    //This ship's window

    int width, height;          //The height and width of the display
    int id;                     // Ship's unique id
    int score;                  // Player's score
public:
    sf::View view;

    float rotation, scale;
    sf::Vector2f position;
    sf::Vector2f velocity;

    Ship(int x, int y);

    sf::RenderWindow getWindow();

    bool Update();
    void Draw();
    void InputHandler();
    bool isOpen();
};
