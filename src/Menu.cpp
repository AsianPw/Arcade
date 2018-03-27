/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <iostream>
#include <dirent.h>
#include <cstring>
#include "../inc/utils.hpp"
#include "Menu.hpp"

void	listFiles(const char* path, std::vector<std::string> &list)
{
	DIR	*dirFile = opendir(path);
	struct dirent	*hFile;

	if (dirFile)
	{
		while ((hFile = readdir( dirFile )) != nullptr) {
			if (!strcmp(hFile->d_name, "." )) continue;
			if (!strcmp(hFile->d_name, "..")) continue;
			if ((hFile->d_name[0] == '.')) continue;
			if (strstr( hFile->d_name, ".so"))
				list.emplace_back(hFile->d_name);
		}
		closedir(dirFile);
	}
}

Menu::Menu()
{
	auto	back = std::string("./res/menu_background.png");
	std::vector<std::string>	graphicLib;
	std::vector<std::string>::iterator	it;

	listFiles(arcade::GRAPHICSDIR, graphicLib);
	it = graphicLib.begin();
	while (it != graphicLib.end()) {
		menuTexture.insert(std::make_pair(*it, createTexture(*it, true, 0, 0)));
		it++;
	}
	menuTexture.insert(std::make_pair<std::string, Texture>("back", createTexture(back, true, 0, 0)));
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
