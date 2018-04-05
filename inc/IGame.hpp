/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_IGAME_HPP
#define CPP_ARCADE_IGAME_HPP

#include <string>

class IGame {
public:
	virtual ~IGame() = 0;
	virtual	std::string	const &getName() const = 0;
	virtual	std::string	const &getDescription() const = 0;
	//virtual	void	Start() = 0;

protected:
	std::string	name;
	std::string	description;
};

#endif //CPP_ARCADE_IGAME_HPP
