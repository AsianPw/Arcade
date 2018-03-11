//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <ncurses.h>
#include "../../../inc/Ncurses.hpp"

NcursesDisplay::NcursesDisplay()
{
	initscr();
}

NcursesDisplay::~NcursesDisplay()
{
	endwin();
}


bool	NcursesDisplay::Display()
{
	refresh();
	return (false);
}

bool	NcursesDisplay::GetKey(arcade::TypeEvent typeEvent)
{
	if (typeEvent == arcade::KEYBOARD)
	{
		//
	}
	return (false);
}