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
	explicit Menu(Loader const&);
	~Menu() override = default;

public:
	virtual void	setBackground(std::string const&path);
	virtual void	addTexture(std::string const&path);

private:
	Loader	const&loader;
};

#endif //CPP_ARCADE_MENU_HPP
