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
	allEvent.insert({arcade::ENTER, SDL_SCANCODE_RETURN});
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Quit();
		throw arcade::GraphicsLibraryError(SDL_GetError());
	}
	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		SDL_Quit();
		throw arcade::GraphicsLibraryError(SDL_GetError());
	}
	windowSurface = SDL_GetWindowSurface(window);//todo check
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	TTF_Init();
	font = TTF_OpenFont("./res/Walk-Around-the-Block.ttf", 30);
}

Sdl2::~Sdl2()
{
	TTF_Quit();
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

bool	Sdl2::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent)
{
	auto	search = allEvent.find(currentEvent);

	if (search == allEvent.end())
		return false;
	if (typeEvent == arcade::WINDOW && search->second == event.window.event)
		return true;
	if (event.type == SDL_KEYUP && typeEvent == arcade::KEYBOARD && search->second == event.key.keysym.scancode)
		return true;
	return false;
}

bool	Sdl2::isKey()
{
	if (!finish)
		return false;
	return SDL_PollEvent(&event) != 0;
}

bool	Sdl2::isOpen()
{
	return finish;
}

bool	Sdl2::Display()
{
	SDL_Rect	rect;

	for (auto const &it : textures) {
		rect.x = it.second.x;
		rect.y = it.second.y;
		rect.w = it.first->w;
		rect.h = it.first->h;
		SDL_BlitSurface(it.first, nullptr, windowSurface, &rect);
	}

	for (auto const &text : texts) {
		rect.x = text.second.x;
		rect.y = text.second.y;
		rect.w = text.first->w;
		rect.h = text.first->h;
		SDL_BlitSurface(text.first, nullptr, windowSurface, &rect);
	}
	SDL_UpdateWindowSurface(window);
	return true;
}

void	Sdl2::destroyWindow()
{
	if (!finish)
		return;
	finish = false;
}

void Sdl2::setEvent(const SDL_Event &event)
{
	Sdl2::event = event;
}

bool Sdl2::loadText(std::map<std::string, Texture> const&text)
{
	SDL_Color	black = {0, 0, 0, 0};

	if (font == nullptr)
		return false;
	for (auto const &currentText : texts)
		SDL_FreeSurface(currentText.first);
	texts.clear();
	for (auto const &it : text) {
		if (it.second.isFile || !it.second.display)
			continue;
		SDL_Surface	*tmpText;

		tmpText = TTF_RenderText_Blended(font, it.second.path.c_str(), black);
		if (tmpText == nullptr)
			continue;
		texts.insert({tmpText, {it.second.position.x, it.second.position.y}});
	}
	return false;
}

bool Sdl2::loadTexture(std::map<std::string, Texture> const&toLoad)
{
	for (auto const &texture : textures)
		SDL_FreeSurface(texture.first);
	textures.clear();
	for (auto const &it : toLoad) {
		if (!it.second.isFile || !it.second.display)
			continue;
		SDL_Surface	*tmpTexture;

		tmpTexture = IMG_Load(it.second.path.c_str());
		if (tmpTexture == nullptr) {
			std::cerr << "Can't load " << it.second.path << std::endl;
			continue;
		}
		textures.insert({tmpTexture, {it.second.position.x, it.second.position.y}});
	}
	return true;
}

template <typename Type>
void	init_texture(std::map<std::string, Texture> const&texture, Type &textureLoad)
{
	auto	it = texture.begin();

	while (it != texture.end()) {

		it++;
	}
}