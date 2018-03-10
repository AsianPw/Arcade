//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#ifndef CPP_ARCADE_IDISPLAY_HPP
#define CPP_ARCADE_IDISPLAY_HPP

class IDisplay {
	public:
	virtual ~IDisplay() = default;

	public:
	virtual bool	Display() = 0;
	virtual bool	BindKey() = 0;
};

#endif //CPP_ARCADE_IDISPLAY_HPP
