/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_SDL2_HPP
#define CPP_ARCADE_SDL2_HPP

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include "utils.hpp"
#include "IDisplay.hpp"

class Sdl2 : public IDisplay {
	public:
	Sdl2(unsigned int width, unsigned int height);
	~Sdl2();

	public:
	bool	Display();
	bool	isOpen();
	bool	GetKey(arcade::TypeEvent, std::string const &);
	bool	isKey();
	void	destroyWindow();

	private:
	std::map<std::string, int>	allEvent;
	bool	finish;
	SDL_Window	*window;
	SDL_Event	event;
	unsigned int	width;
	unsigned int	height;
};

#endif //CPP_ARCADE_SDL2_HPP
