//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <ncurses.h>
#include "../../../inc/Ncurses.hpp"

extern "C" IDisplay* create_object(unsigned int w, unsigned int h)
{
	return new NcursesDisplay(w, h);
}

extern "C" void destroy_object(IDisplay* object)
{
	delete object;
}


NcursesDisplay::NcursesDisplay(unsigned int w, unsigned int h)
{
	(void)w;
	(void)h;
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

bool	NcursesDisplay::isOpen()
{
	return (true);
}

bool	NcursesDisplay::isKey()
{
	return (false);
}

bool	NcursesDisplay::GetKey(arcade::TypeEvent typeEvent, std::string const &type)
{
	(void)typeEvent;
	(void)type;
	return (false);
}

void	NcursesDisplay::destroyWindow()
{
	endwin();
}