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

extern "C" IDisplay* create_object(unsigned int w, unsigned int h)
{
	return new Vulkan(w, h);
}

extern "C" void destroy_object(IDisplay* object)
{
	delete object;
}


Vulkan::Vulkan(unsigned int width, unsigned int height){
	uint32_t	extensionCount = 0;

	this->width = width;
	this->height = height;
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
	if (search == allEvent.end())
		return (false);
	return (false);
}

bool	Vulkan::isKey()
{
	return (true);
}

bool	Vulkan::isOpen()
{
	glfwPollEvents();
	return (!glfwWindowShouldClose(window));
}

bool	Vulkan::Display()
{
	return (false);
}

void	Vulkan::destroyWindow()
{
	glfwDestroyWindow(window);
}