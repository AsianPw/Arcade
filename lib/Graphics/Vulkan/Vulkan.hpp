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
	bool	loadTexture(std::map<std::string, Texture> const&);
	bool	loadText(std::map<std::string, Texture> const&);
	void destroyWindow();
private:
	std::map<std::string, int> allEvent;
	GLFWwindow *window;
	size_t width;
public:
	void changeLibrary(std::string const &path) override;

	bool getChange() const override;

	void setChange(bool b) override;

	const std::string &getLibraryPath() const override;

private:
	size_t height;
};

#endif //CPP_ARCADE_VULKAN_HPP
