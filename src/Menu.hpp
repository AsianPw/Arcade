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
	~Menu();
	void	sceneEvent(IDisplay *) override;
};

#endif //CPP_ARCADE_MENU_HPP
