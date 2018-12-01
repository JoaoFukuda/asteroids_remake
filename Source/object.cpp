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

#include "object.hpp"

Ship::Ship(int x, int y)
{
    width = x;
    height = y;
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ship #1", sf::Style::None);
    window.setFramerateLimit(1000);
    monitorOffset = sf::Vector2i(0, 0);
    position = sf::Vector2f(x/2, y/2);
    velocity = sf::Vector2f(0, 0);
    scale = 10;
    rotation = 0;
    view = sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    shape.setPointCount(4);
    shape.setOrigin(0, 0);
    shape.setPoint(0, sf::Vector2f(
        cos(rotation),
        sin(rotation)
    )*scale);
    shape.setPoint(1, sf::Vector2f(
        cos(rotation - PI*3/4),
        sin(rotation - PI*3/4)
    )*scale);
    shape.setPoint(2, sf::Vector2f(0, 0));
    shape.setPoint(3, sf::Vector2f(
        cos(rotation + PI*3/4),
        sin(rotation + PI*3/4)
    )*scale);
}

void Ship::setMonitorOffset(int x, int y)
{
    monitorOffset = sf::Vector2i(x, y);
}

void Ship::InputHandler()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) rotation -= 0.5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) rotation += 0.5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity = velocity + sf::Vector2f(
            cos(rotation*2*PI/360) * 0.0006,
            sin(rotation*2*PI/360) * 0.0006
        );
    }
}

bool Ship::isOpen()
{
    return window.isOpen();
}

bool Ship::Update()
{
    position = position + velocity;
    if(position.x < -scale*2) position.x = width + scale*2;
    else if(position.x > width + scale*2) position.x = -scale*2;
    if(position.y < -scale*2) position.y = height + scale*2;
    else if(position.y > height + scale*2) position.y = -scale*2;
    return false;
}

void Ship::Draw()
{
    int x, y;
    x = position.x - WINDOW_WIDTH/2;
    if(x < 0) x = 0;
    else if(x >= width-WINDOW_WIDTH) x = width-WINDOW_WIDTH;
    y = position.y - WINDOW_HEIGHT/2;
    if(y < 0) y = 0;
    else if(y >= height-WINDOW_HEIGHT) y = height-WINDOW_HEIGHT;

    view.setCenter(sf::Vector2f(x + WINDOW_WIDTH/2, y + WINDOW_HEIGHT/2));
    window.setPosition(sf::Vector2i(x, y) + monitorOffset);
    shape.setRotation(rotation);
    shape.setPosition(position);
    window.clear();
    window.draw(shape);
    window.setView(view);
    window.display();
}
