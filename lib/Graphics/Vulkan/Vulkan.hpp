/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_VULKAN_HPP
#define CPP_ARCADE_VULKAN_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <map>
#include "../../../inc/IDisplay.hpp"

class Vulkan : public IDisplay {
public:
	Vulkan(size_t, size_t);
	~Vulkan();
public:
	bool Display();
	bool isOpen();
	bool GetKey(arcade::TypeEvent, std::string const &);
	bool isKey();
	void destroyWindow();
private:
	std::map<std::string, int> allEvent;
	GLFWwindow *window;
	size_t width;
	size_t height;
};

#endif //CPP_ARCADE_VULKAN_HPP
