/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_MENU_HPP
#define CPP_ARCADE_MENU_HPP

#include "../inc/IScene.hpp"
#include "../inc/Loader.hpp"
#include "../inc/IGame.hpp"
#include "../inc/GameLoader.hpp"
#include "../inc/Alias.hpp"

static const char PRESS[] = "Press Enter";

class Menu : public IScene {
public:
	explicit Menu();
	~Menu() override = default;
	void		sceneEvent(IDisplay *) override;
	textureList	getTexture() const override;
	textureList	getText() const override;
	mapChar 	getMap() const override;
	void		compute() override;
private:
	textureList	menuTexture;
	textureList	menuText;
	mapChar		menuMap;
	stringList	*current;
	stringList	graphicLib;
	stringList	gamesLib;
	long	currentTime;
};

#endif //CPP_ARCADE_MENU_HPP
