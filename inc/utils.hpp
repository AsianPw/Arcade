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
#include <string>

namespace arcade {
	enum TypeEvent {
		WINDOW,
		JOYSTICK,
		KEYBOARD,
		MOUSE
	};

	static const std::string ESCAPE = "ESCAPE";
	static const std::string CLOSE = "CLOSE";
	static const std::string UP = "UP";
	static const std::string DOWN = "DOWN";
	static const std::string LEFT = "LEFT";
	static const std::string RIGHT = "RIGHT";
}

bool checkFileExist(std::string const &) noexcept;

#endif //CPP_ARCADE_UTILS_HPP
