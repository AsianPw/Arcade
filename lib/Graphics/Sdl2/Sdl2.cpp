/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "../../../inc/Sdl2.hpp"

extern "C" IDisplay* create_object(unsigned int w, unsigned int h)
{
	return new Sdl2(w, h);
}

extern "C" void destroy_object(IDisplay* object)
{
	delete object;
}


Sdl2::Sdl2(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
	finish = true;
	allEvent.insert(std::pair<std::string, int>(arcade::CLOSE, SDL_WINDOWEVENT_CLOSE));
	allEvent.insert(std::pair<std::string, int>(arcade::ESCAPE, SDL_SCANCODE_ESCAPE));
	allEvent.insert(std::pair<std::string, int>(arcade::UP, SDL_SCANCODE_UP));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();
	} else {
		window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cerr << "Erreur lors de la creation de la fenetre SDL : " << SDL_GetError() << std::endl;
			SDL_Quit();
		}
	}
}

Sdl2::~Sdl2()
{
	SDL_Quit();
}

bool	Sdl2::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent)
{
	auto	search = allEvent.find(currentEvent);

	std::cout << "Key pressed" << std::endl;
	if (search == allEvent.end())
		return (false);
	if (typeEvent == arcade::WINDOW && search->second == event.window.event)
		return (true);
	if (typeEvent == arcade::KEYBOARD && search->second == event.key.keysym.scancode)
		return (true);
	return (false);
}

bool	Sdl2::isKey()
{
	if (SDL_PollEvent(&event) == 0)
		return (false);
	return (true);
}

bool	Sdl2::isOpen()
{
	return (finish);
}

bool	Sdl2::Display()
{
	return (false);
}

void	Sdl2::destroyWindow()
{
	finish = false;
	SDL_DestroyWindow(window);
}