/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "Menu.hpp"

Menu::Menu()
{
	//sceneTexture.insert("back", createTexture(BACKGROUND, true, 0, 0));
}

void	Menu::sceneEvent(IDisplay *display)
{
	if (display->GetKey(arcade::WINDOW, arcade::CLOSE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::UP))
		std::cout << "Arrow Up is pressed !" << std::endl;
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN))
		std::cout << "Arrow Down is pressed !" << std::endl;
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT))
		std::cout << "Arrow Left is pressed !" << std::endl;
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT))
		std::cout << "Arrow Right is pressed !" << std::endl;
}

Menu::~Menu()
{
}