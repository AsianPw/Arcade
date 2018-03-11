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
	NcursesDisplay();
	~NcursesDisplay();

	public:
	bool	Display();
	bool	GetKey(arcade::TypeEvent typeEvent);
};

#endif //CPP_ARCADE_NCURSES_HPP
