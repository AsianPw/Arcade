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
	size_t	x;
	size_t	y;
};

struct Texture {
	std::string	path;
	bool		isFile;
	bool		display;
	Position	position;
};

Texture	createTexture(std::string, bool, size_t, size_t);

#endif //CPP_ARCADE_TEXTURE_HPP
