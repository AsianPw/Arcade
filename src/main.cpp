//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstdlib>
#include <iostream>
#include <bits/unique_ptr.h>
#include "../inc/IScene.hpp"
#include "../inc/Loader.hpp"
#include "../inc/ArcadeException.hpp"
#include "Menu.hpp"

Texture	createTexture(std::string path, bool state, size_t x, size_t y)
{
	Texture	newTexture;

	newTexture.isFile = checkFileExist(path);
	newTexture.position = {x,y};
	newTexture.path = path;
	newTexture.display = state;
	return (newTexture);
}

void	printHelp(const char *binaryName)
{
	std::cerr << "USAGE:" << std::endl
		<< binaryName << " path_to_graphic_library" << std::endl;
}

int	startArcade(char *libraryPath)
{
	auto			menu = std::make_unique<Menu>();
	std::unique_ptr<Loader>	loader = nullptr;
	IDisplay		*display = nullptr;

	if (!checkFileExist(libraryPath)) {
		std::cerr << libraryPath << " doesn't exist" << std::endl;
		return (84);
	}
	try {
		loader = std::make_unique<Loader>(libraryPath);
	} catch (arcade::LoaderError const& e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
	display = loader->create(arcade::WIDTH, arcade::HEIGHT);
	while (display->isOpen()) {
		while (display->isKey())
			menu->sceneEvent(display);
		display->loadTexture(menu->getTexture());
		display->loadText(menu->getText());
		menu->compute();
		display->Display();
	}
	loader->destroy(display);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	exitValue = EXIT_SUCCESS;

	if (ac == 2)
		exitValue = startArcade(av[1]);
	else
		printHelp(av[0]);
	return exitValue;
}