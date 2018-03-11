/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_LOADER_HPP
#define CPP_ARCADE_LOADER_HPP

#include "IDisplay.hpp"

class Loader {
	public:
	explicit Loader(char *library_path);
	~Loader();

	public:
	IDisplay	*(*create)(unsigned int, unsigned int);
	void		(*destroy)(IDisplay*);

	private:
	void		*handle;
};

#endif //CPP_ARCADE_LOADER_HPP
