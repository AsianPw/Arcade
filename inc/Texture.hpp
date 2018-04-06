/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Texture
*/

#ifndef CPP_ARCADE_TEXTURE_HPP
#define CPP_ARCADE_TEXTURE_HPP

#include <cstddef>
#include <string>

struct Position {
	int	x;
	int	y;
};

struct Texture {
	std::string	path;
	bool		isFile;
	bool		display;
	Position	position;
};

Texture	createTexture(std::string, bool, int, int);

#endif //CPP_ARCADE_TEXTURE_HPP
