/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_ISCENE_HPP
#define CPP_ARCADE_ISCENE_HPP

#include <string>
#include <map>
#include "IDisplay.hpp"
#include "Texture.hpp"

class IScene {
public:
	virtual	~IScene() = default;
	virtual void	sceneEvent(IDisplay *) = 0;

};

#endif //CPP_ARCADE_ISCENE_HPP
