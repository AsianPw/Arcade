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
	auto	back = std::string("./res/menu_background.png");
	auto	first = std::string("first game");
	auto	second = std::string("second game");

	menuTexture.insert(std::make_pair<std::string, Texture>("back", createTexture(back, true, 0, 0)));
	menuTexture.insert(std::make_pair("first", createTexture(first, true, 0, 0)));
	menuTexture.insert(std::make_pair("second", createTexture(second, true, 0, 60)));
}

void	Menu::sceneEvent(IDisplay *display)
{
	if (display->GetKey(arcade::WINDOW, arcade::CLOSE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::UP))
		menuTexture["back"].position.y -= 10;
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN))
		menuTexture["back"].position.y += 10;
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT))
		menuTexture["back"].position.x -= 10;
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT))
		menuTexture["back"].position.x += 10;
}

void	Menu::compute()
{
}

inline std::map<std::string, Texture> Menu::getTexture() const
{
	return (menuTexture);
}