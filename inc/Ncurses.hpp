/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_NCURSES_HPP
#define CPP_ARCADE_NCURSES_HPP

#include <string>
#include <map>
#include <ncurses.h>
#include "IDisplay.hpp"

class NcursesDisplay : public IDisplay {
public:
	NcursesDisplay(size_t, size_t);
	~NcursesDisplay();
public:
	bool Display();
	bool isOpen();
	bool GetKey(arcade::TypeEvent typeEvent, std::string const &type);
	bool isKey();
	void destroyWindow();
private:
	std::map<std::string, int> allEvent;
	int currentKey;
	WINDOW *window;
};

#endif //CPP_ARCADE_NCURSES_HPP
