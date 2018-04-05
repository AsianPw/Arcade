//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <ncurses.h>
#include <iostream>
#include "../../../inc/Ncurses.hpp"

NcursesDisplay::NcursesDisplay(size_t w, size_t h)
{
	(void)w;
	(void)h;
	allEvent.insert(std::pair<std::string, int>(arcade::UP, KEY_UP));
	allEvent.insert(std::pair<std::string, int>(arcade::DOWN, KEY_DOWN));
	allEvent.insert(std::pair<std::string, int>(arcade::LEFT, KEY_LEFT));
	allEvent.insert(std::pair<std::string, int>(arcade::RIGHT, KEY_RIGHT));
	allEvent.insert(std::pair<std::string, int>(arcade::ESCAPE, 113));
	initscr();
	cbreak();
	//window = newwin(h, w, 0, 0);
	keypad(stdscr, true);
	nodelay(stdscr, true);
}

NcursesDisplay::~NcursesDisplay()
{
	clear();
	refresh();
	endwin();
}


bool	NcursesDisplay::Display()
{
	//clear();
	refresh();
	return (false);
}

bool	NcursesDisplay::isOpen()
{
	currentKey = getch();
	return (true);
}

bool	NcursesDisplay::isKey()
{
	return currentKey != ERR;
}

bool	NcursesDisplay::GetKey(arcade::TypeEvent typeEvent, std::string const &type)
{
	auto	search = allEvent.find(type);
	int	tmpKey = currentKey;

	currentKey = ERR;
	printw("%d key press\n", tmpKey);
	//wprintw(window, "%d key press\n", tmpKey);
	if (search == allEvent.end())
		return (false);
	(void)typeEvent;
	if (search->second == tmpKey)
		return (true);
	return (false);
}

void	NcursesDisplay::destroyWindow()
{
	//wprintw(window, "delete\n");
	//delwin(window);
	endwin();
}

bool NcursesDisplay::loadText(std::map<std::string, Texture> const&text)
{
	return false;
}

bool NcursesDisplay::loadTexture(std::map<std::string, Texture> const &texture)
{
	return false;
}

void NcursesDisplay::changeLibrary(std::string const &path)
{
}

bool NcursesDisplay::getChange() const
{
	return false;
}

void NcursesDisplay::setChange(bool b)
{
}

const std::string &NcursesDisplay::getLibraryPath() const
{
	return newLibraryPath;
}
