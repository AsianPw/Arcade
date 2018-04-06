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
	~Vulkan() override;
public:
	bool Display() override;
	bool isOpen() override;
	bool GetKey(arcade::TypeEvent, std::string const &) override;
	bool isKey() override;
	bool	loadTexture(std::map<std::string, Texture> const&) override;
	bool	loadText(std::map<std::string, Texture> const&) override;
	void destroyWindow() override;
	void changeLibrary(std::string const &path) override;
	bool getChange() const override;
	void setChange(bool b) override;
	const std::string &getLibraryPath() const override;
	bool loadMap(std::vector<std::vector<char>> const &vector) override;
	const std::string &getNewGamePath() const override;
	void setNewGamePath(std::string const &string) override;
	bool getSwitchScene() const override;
//	void setSwitchScene(bool) override;
private:
	std::map<std::string, int> allEvent;
	GLFWwindow *window;
	size_t width;
	size_t height;
};

#endif //CPP_ARCADE_VULKAN_HPP
