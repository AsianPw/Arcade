/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#define GLFW_INCLUDE_VULKAN
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <iostream>
#include "Vulkan.hpp"

// When I wrote this,
// only God and I understood what I was doing
// Now, God only knows


Vulkan::Vulkan(size_t width, size_t height) : width(width), height(height)
{
	uint32_t	extensionCount = 0;

	glfwInit();//todo exception
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(width, height, "Arcade - Vulkan", nullptr, nullptr);
	allEvent.insert({arcade::ESCAPE, GLFW_KEY_ESCAPE});
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
}

Vulkan::~Vulkan()
{
	glfwTerminate();
}

bool	Vulkan::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent)
{
	for (auto const &key : allEvent) {
		if (key.first == currentEvent && glfwGetKey(window, key.second) != GLFW_PRESS)
			return true;
	}
	return false;
}

bool	Vulkan::isKey()
{
	return true;
}

bool	Vulkan::isOpen()
{
	glfwPollEvents();
	return !glfwWindowShouldClose(window);
}

bool	Vulkan::Display()
{
	return false;
}

void	Vulkan::destroyWindow()
{
	glfwDestroyWindow(window);
}

bool Vulkan::loadText(std::map<std::string, Texture> const& text)
{
	(void)text;
	return false;
}

bool Vulkan::loadTexture(std::map<std::string, Texture> const& texture)
{
	(void)texture;
	return false;
}

void Vulkan::changeLibrary(std::string const &path)
{
	change = true;
	newLibraryPath = path;
}

bool Vulkan::getChange() const
{
	return change;
}

void Vulkan::setChange(bool state)
{
	change = state;
}

const std::string &Vulkan::getLibraryPath() const
{
	return newLibraryPath;
}

bool Vulkan::loadMap(std::vector<std::vector<char>> const &map)
{
	(void)map;
	return false;
}

const std::string &Vulkan::getNewGamePath() const
{
	return newGamePath;
}

void Vulkan::setNewGamePath(std::string const &path)
{
	newGamePath = path;
}

bool Vulkan::getSwitchScene() const
{
	return switchScene;
}

void Vulkan::setSwitchScene(bool state)
{
	switchScene = state;
}
