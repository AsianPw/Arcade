/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_NCURSES_HPP
#define CPP_ARCADE_NCURSES_HPP

#include "IDisplay.hpp"

class NcursesDisplay : public IDisplay {
	public:
	NcursesDisplay(unsigned int, unsigned int);
	~NcursesDisplay();

	public:
	bool	Display();
	bool	isOpen();
	bool	GetKey(arcade::TypeEvent typeEvent, char *type);
	bool	isKey();
	void	destroyWindow();
};

#endif //CPP_ARCADE_NCURSES_HPP
