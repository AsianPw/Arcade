/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_MENU_HPP
#define CPP_ARCADE_MENU_HPP

#include <ctime>
#include <chrono>
#include "../inc/IScene.hpp"
#include "../inc/Loader.hpp"
#include "../inc/IGame.hpp"
#include "../inc/GameLoader.hpp"

static const char PRESS[] = "Press Enter";

class Menu : public IScene {
public:
	explicit Menu();
	~Menu() override = default;
	void	sceneEvent(IDisplay *) override;
	std::map<std::string, Texture>	getTexture() const override;
	std::map<std::string, Texture>	getText() const override;
	std::vector<std::vector<char>> getMap() const override;
	void	compute() override;
private:
	std::map<std::string, Texture>	menuTexture;
	std::map<std::string, Texture>	menuText;
	std::vector<std::vector<char>>	menuMap;
	std::vector<std::string>	*current;
	std::vector<std::string>	graphicLib;
	std::vector<std::string>	gamesLib;
	long	currentTime;
};

#endif //CPP_ARCADE_MENU_HPP
