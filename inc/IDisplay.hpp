//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#ifndef CPP_ARCADE_IDISPLAY_HPP
#define CPP_ARCADE_IDISPLAY_HPP

#include <string>
#include "utils.hpp"

class IDisplay {
	public:
	virtual ~IDisplay() = default;

	public:
	virtual bool	Display() = 0;
	virtual bool	isKey() = 0;
	virtual bool	isOpen() = 0;
	virtual bool	GetKey(arcade::TypeEvent, std::string const &) = 0;
	virtual void	destroyWindow() = 0;
};

#endif //CPP_ARCADE_IDISPLAY_HPP
