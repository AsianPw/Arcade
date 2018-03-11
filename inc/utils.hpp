//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#ifndef CPP_ARCADE_UTILS_HPP
#define CPP_ARCADE_UTILS_HPP

#include <cstdint>
#include <vector>

namespace arcade {
	enum TypeEvent {
		WINDOW,
		JOYSTICK,
		KEYBOARD,
		MOUSE
	};

	static const std::string	ESCAPE = "ESCAPE";
	static const std::string	CLOSE = "CLOSE";
}

std::vector<uint8_t>	*createFramebuffer(size_t, size_t, size_t);

#endif //CPP_ARCADE_UTILS_HPP
