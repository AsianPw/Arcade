/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_ISCENE_HPP
#define CPP_ARCADE_ISCENE_HPP

#include <string>

class IScene {
public:
	virtual ~IScene() = 0;

public:
	virtual void	setBackground(std::string const&path) = 0;
	virtual void	addTexture(std::string const&path) = 0;
	virtual void	setEvent() = 0;
};

#endif //CPP_ARCADE_ISCENE_HPP
