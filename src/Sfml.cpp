/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <SFML/Window.hpp>
#include "../inc/Sfml.hpp"

SfmlDisplay::SfmlDisplay(uint width, uint height){
	this->width = width;
	this->height = height;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Arcade");
}

bool	SfmlDisplay::Display()
{
	window->clear();
	window->display();
	return (true);
}

bool	SfmlDisplay::BindKey()
{
	return (true);
}