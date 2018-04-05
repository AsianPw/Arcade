//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Nibbler.cpp
//

#include <vector>
#include "Nibbler.hpp"

Nibbler::Nibbler()
{
	this->name = "Nibbler";
	this->description = "";
}

std::string	const&Nibbler::getDescription() const
{
	return description;
}

std::string	const&Nibbler::getName() const
{
	return name;
}