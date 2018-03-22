/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <SFML/Window.hpp>
#include <iostream>
#include "Sfml.hpp"

SfmlDisplay::SfmlDisplay(size_t w, size_t h) : width(w), height(h)//, window(sf::VideoMode(width,height), "SFML")
{
	window = new sf::RenderWindow(sf::VideoMode(width,height), "SFML");
	allEvent.insert(std::make_pair(arcade::CLOSE, sf::Event::Closed));
	allEvent.insert(std::make_pair(arcade::ESCAPE,sf::Keyboard::Escape));
	allEvent.insert(std::make_pair(arcade::UP,sf::Keyboard::Up));
	allEvent.insert(std::make_pair(arcade::DOWN,sf::Keyboard::Down));
	allEvent.insert(std::make_pair(arcade::LEFT,sf::Keyboard::Left));
	allEvent.insert(std::make_pair(arcade::RIGHT,sf::Keyboard::Right));
}

SfmlDisplay::~SfmlDisplay()
{
}

bool	SfmlDisplay::Display()
{
	window->clear();
	window->display();
	return true;
}

bool	SfmlDisplay::isKey()
{
	return window->pollEvent(event);
}

bool	SfmlDisplay::isOpen()
{
	return window->isOpen();
}

bool	SfmlDisplay::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent){
	auto	search = allEvent.find(currentEvent);

	if (search == allEvent.end())
		return false;
	if (typeEvent == arcade::WINDOW && event.type == search->second)
		return true;
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == search->second)
			return true;
	}
	return false;
}

void	SfmlDisplay::destroyWindow()
{
	window->close();
}

void	SfmlDisplay::setEvent(sf::Event &newEvent)
{
	event = newEvent;
}