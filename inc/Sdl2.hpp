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
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "utils.hpp"
#include "IDisplay.hpp"

class Sdl2 : public IDisplay {
public:
	Sdl2(size_t, size_t);
	~Sdl2() override;
public:
	bool Display() override;
	bool isOpen() override;
	bool GetKey(arcade::TypeEvent, std::string const &) override;
	bool isKey() override;
	bool	loadTexture(std::map<std::string, Texture> const&) override;
	bool	loadText(std::map<std::string, Texture> const&) override;
	void destroyWindow() override;
	void changeLibrary(std::string const &) override;
	bool	getChange() const override;
	void	setChange(bool) override;
	std::string const	&getLibraryPath() const override;
	void setEvent(const SDL_Event &event);
private:
	size_t width;
	size_t height;
	bool finish;
	TTF_Font	*font;
	std::map<std::string, int> allEvent;
	std::map<SDL_Surface*, Position>	texts;
	std::map<SDL_Surface*, Position>	textures;
	SDL_Surface	*windowSurface;
	SDL_Window	*window;
	SDL_Event event;
};

#endif //CPP_ARCADE_SDL2_HPP
