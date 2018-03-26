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
	window = glfwCreateWindow(width, height, "Arcade - Vulkan", nullptr, nullptr);//todo exception
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::cout << extensionCount << " extensions supported" << std::endl;
}

Vulkan::~Vulkan()
{
	glfwTerminate();
}

bool	Vulkan::GetKey(arcade::TypeEvent typeEvent, std::string const &currentEvent)
{
	auto	search = allEvent.find(currentEvent);

	(void)typeEvent;
	if (search == allEvent.end()) {
		return false;
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
	return false;
}

bool Vulkan::loadTexture(std::map<std::string, Texture> const& texture)
{
	return false;
}