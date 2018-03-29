/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <SFML/Window.hpp>
#include <iostream>
#include "Sfml.hpp"

SfmlDisplay::SfmlDisplay(size_t w, size_t h) : width(w), height(h), alreadyLoad(false)//, window(sf::VideoMode(width,height), "SFML")
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
	auto	it = sprites.begin();
	auto	textIt = texts.begin();

	window->clear();
	while (it != sprites.end()) {
		window->draw(it->second);
		it++;
	}
	while (textIt != texts.end()) {
		window->draw(*textIt);
		textIt++;
	}
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

bool	SfmlDisplay::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent)
{
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

bool SfmlDisplay::loadTexture(std::map<std::string, Texture> const &texture)
{
	auto	it = texture.begin();

	textures.clear();
	sprites.clear();
	while (it != texture.end()) {
		sf::Texture	newTexture;
		if (it->second.isFile && it->second.display && newTexture.loadFromFile(it->second.path)) {
			sf::Sprite	newSprite;
			textures.emplace_back(newTexture);
			newSprite.setTexture(textures.back());
			newSprite.setPosition(it->second.position.x, it->second.position.y);
			sprites.insert(std::make_pair(it->first, newSprite));
		}
		it++;
	}
	return true;
}

bool SfmlDisplay::loadText(std::map<std::string, Texture> const &text)
{
	auto	it = text.begin();

	texts.clear();
	if (!font.loadFromFile("./res/Walk-Around-the-Block.ttf"))
		return false;
	while (it != text.end()) {
		if (!it->second.isFile && it->second.display) {
			sf::Text	newText(it->second.path, font);
			newText.setPosition(it->second.position.x, it->second.position.y);
			texts.emplace_back(newText);
		}
		it++;
	}
	return true;
}