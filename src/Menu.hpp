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



class Menu : public IScene {
public:
	explicit Menu();
	~Menu() override = default;
	void	sceneEvent(IDisplay *) override;
	std::map<std::string, Texture>	getTexture() const override;
	std::map<std::string, Texture>	getText() const override;
	void	compute() override;

private:
	std::map<std::string, Texture>	menuTexture;
	std::map<std::string, Texture>	menuText;
	std::vector<std::string>	*current;
	std::vector<std::string>	graphicLib;
	std::vector<std::string>	gamesLib;
	//std::pair<std::vector<std::string>, int>	&current;
};

#endif //CPP_ARCADE_MENU_HPP
