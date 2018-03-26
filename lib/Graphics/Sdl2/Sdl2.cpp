/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "../../../inc/Sdl2.hpp"
#include "../../../inc/ArcadeException.hpp"

Sdl2::Sdl2(size_t w, size_t h)
{
	width = w;
	height = h;
	finish = true;
	allEvent.insert(std::make_pair(arcade::CLOSE, SDL_WINDOWEVENT_CLOSE));
	allEvent.insert(std::make_pair(arcade::ESCAPE, SDL_SCANCODE_ESCAPE));
	allEvent.insert(std::make_pair(arcade::UP, SDL_SCANCODE_UP));
	allEvent.insert(std::make_pair(arcade::DOWN, SDL_SCANCODE_DOWN));
	allEvent.insert(std::make_pair(arcade::LEFT, SDL_SCANCODE_LEFT));
	allEvent.insert(std::make_pair(arcade::RIGHT, SDL_SCANCODE_RIGHT));
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Quit();
		throw arcade::GraphicsLibraryError(SDL_GetError());
	}
	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		SDL_Quit();
		throw arcade::GraphicsLibraryError(SDL_GetError());
	}
}

Sdl2::~Sdl2()
{
	SDL_Quit();
}

bool	Sdl2::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent)
{
	auto	search = allEvent.find(currentEvent);

	if (search == allEvent.end())
		return false;
	if (typeEvent == arcade::WINDOW && search->second == event.window.event)
		return true;
	if (typeEvent == arcade::KEYBOARD && search->second == event.key.keysym.scancode)
		return true;
	return false;
}

bool	Sdl2::isKey()
{
	return SDL_PollEvent(&event) != 0;
}

bool	Sdl2::isOpen()
{
	return finish;
}

bool	Sdl2::Display()
{
	return true;
}

void	Sdl2::destroyWindow()
{
	finish = false;
	SDL_DestroyWindow(window);
}

void Sdl2::setEvent(const SDL_Event &event)
{
	Sdl2::event = event;
}

bool Sdl2::loadText(std::map<std::string, Texture> const&text)
{
	return false;
}

bool Sdl2::loadTexture(std::map<std::string, Texture> const&texture)
{
	return false;
}
