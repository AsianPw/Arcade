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
	DIR		*dirFile = opendir(path);
	struct dirent	*hFile;

	if (dirFile)
	{
		while ((hFile = readdir( dirFile )) != nullptr) {
			if (!strcmp(hFile->d_name, "." )) continue;
			if (!strcmp(hFile->d_name, "..")) continue;
			if ((hFile->d_name[0] == '.')) continue;
			if (strstr(hFile->d_name, ".so"))
				list.emplace_back(hFile->d_name);
		}
		closedir(dirFile);
	}
}

void	init_text(char const *dir, std::vector<std::string> &list, std::map<std::string, Texture> &text, Position &pos)
{
	size_t	count = 0;

	listFiles(dir, list);
	for (auto const &current : list) {
		text.insert({current, createTexture(current, count == 0, pos.x, pos.y)});
		count += 1;
	}
}

Menu::Menu()
{
	Position	pos = {200, 300};

	init_text(arcade::GRAPHICSDIR, graphicLib, menuText, pos);
	pos.y = 500;
	init_text(arcade::GAMESDIR, gamesLib, menuText, pos);
	menuTexture.insert({"cursor", createTexture("./res/menu_cursor.png", true, 140, 300)});
	menuTexture.insert({"0", createTexture("./res/menu_wallpaper.jpeg", true, 0, 0)});
	menuTexture.insert({"champi", createTexture("./res/menu_champi.png", true, 80, 130)});
	menuTexture.insert({"mario", createTexture("./res/menu_mario.png", true, 0, 100)});
	current = &graphicLib;
}

void	Menu::sceneEvent(IDisplay *display)
{
	auto	it = current->begin();
	size_t	count = 0;

	if (display->GetKey(arcade::WINDOW, arcade::CLOSE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::UP)) {
		if (menuTexture["cursor"].position.y == 500) {
			menuTexture["cursor"].position.y -= 200;
			current = &graphicLib;
		}
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN)) {
		if (menuTexture["cursor"].position.y == 300) {
			menuTexture["cursor"].position.y += 200;
			current = &gamesLib;
		}
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		while (it != current->end()) {
			if (count > 0 && menuText[*it].display) {
				menuText[*it].display = false;
				menuText[*--it].display = true;
				break;
			}
			count += 1;
			it++;
		}
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		while (it != current->end()) {
			if (current->size() - 1 > count && menuText[*it].display) {
				menuText[*it].display = false;
				menuText[*++it].display = true;
				break;
			}
			count += 1;
			it++;
		}
	}
}

void	Menu::compute()
{
	menuTexture["champi"].position.x += 2;
	menuTexture["mario"].position.x += 2;
	if (menuTexture["champi"].position.x > 800)
		menuTexture["champi"].position.x = 0;
	if (menuTexture["mario"].position.x > 800)
		menuTexture["mario"].position.x = 0;
}

std::map<std::string, Texture> Menu::getText() const
{
	return menuText;
}

std::map<std::string, Texture> Menu::getTexture() const
{
	return menuTexture;
}