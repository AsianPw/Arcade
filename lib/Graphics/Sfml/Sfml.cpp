/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <SFML/Window.hpp>
#include <iostream>
#include "../../../inc/Sfml.hpp"

extern "C" IDisplay	*create_object(unsigned int w, unsigned int h)
{
	return new SfmlDisplay(w, h);
}

extern "C" void	destroy_object(IDisplay* object)
{
	delete object;
}

SfmlDisplay::SfmlDisplay(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "SFML");
	allEvent.insert(std::pair<std::string, int>(arcade::CLOSE,sf::Event::Closed));
	allEvent.insert(std::pair<std::string, int>(arcade::ESCAPE,sf::Keyboard::Escape));
	allEvent.insert(std::pair<std::string, int>(arcade::UP,sf::Keyboard::Up));
	allEvent.insert(std::pair<std::string, int>(arcade::DOWN,sf::Keyboard::Down));
	allEvent.insert(std::pair<std::string, int>(arcade::LEFT,sf::Keyboard::Left));
	allEvent.insert(std::pair<std::string, int>(arcade::RIGHT,sf::Keyboard::Right));
}

SfmlDisplay::~SfmlDisplay()
{
	if (window)
		window->close();
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