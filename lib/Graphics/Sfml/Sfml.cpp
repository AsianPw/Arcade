/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <SFML/Window.hpp>
#include <iostream>
#include "Sfml.hpp"

SfmlDisplay::SfmlDisplay(size_t w, size_t h) : width(w), height(h), alreadyLoad(false)
{
	window = new sf::RenderWindow(sf::VideoMode(width,height), "SFML");
	allEvent.insert({arcade::CLOSE, sf::Event::Closed});
	allEvent.insert({arcade::ESCAPE,sf::Keyboard::Escape});
	allEvent.insert({arcade::UP,sf::Keyboard::Up});
	allEvent.insert({arcade::DOWN,sf::Keyboard::Down});
	allEvent.insert({arcade::LEFT,sf::Keyboard::Left});
	allEvent.insert({arcade::RIGHT,sf::Keyboard::Right});
	allEvent.insert({arcade::ENTER, sf::Keyboard::Return});
}

SfmlDisplay::~SfmlDisplay()
{
}

bool	SfmlDisplay::Display()
{
	window->clear();
	for (auto const &it : sprites)
		window->draw(it.second);
	for (auto const &it : texts)
		window->draw(it);
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
	if (event.type == sf::Event::KeyPressed && event.key.code == search->second)
		return true;
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
	textures.clear();
	sprites.clear();
	for (auto const &it : texture) {
		sf::Texture	newTexture;
		if (it.second.isFile && it.second.display && newTexture.loadFromFile(it.second.path)) {
			sf::Sprite	newSprite;
			textures.emplace_back(newTexture);
			newSprite.setTexture(textures.back());
			newSprite.setPosition(it.second.position.x, it.second.position.y);
			sprites.insert(std::make_pair(it.first, newSprite));
		}
	}
	return true;
}

bool SfmlDisplay::loadText(std::map<std::string, Texture> const &text)
{
	texts.clear();
	if (!font.loadFromFile("./res/Walk-Around-the-Block.ttf"))
		return false;
	for (auto const &it : text) {
		if (!it.second.isFile && it.second.display) {
			sf::Text	newText(it.second.path, font);
			newText.setPosition(it.second.position.x, it.second.position.y);
			texts.emplace_back(newText);
		}
	}
	return true;
}