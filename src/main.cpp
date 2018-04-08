//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstdlib>
#include <iostream>
#include <bits/unique_ptr.h>
#include <cstring>
#include "../inc/IScene.hpp"
#include "../inc/Loader.hpp"
#include "../inc/ArcadeException.hpp"
#include "../inc/Menu.hpp"
#include "../inc/GameLoader.hpp"
#include "../inc/Core.hpp"

[[deprecated("Add to few arguments")]] Texture	createTexture(std::string path, bool state, Position pos, char similar)
{
	Texture	newTexture;

	newTexture.isFile = checkFileExist(path);
	newTexture.position = pos;
	newTexture.similar = similar;
	newTexture.path = path;
	newTexture.display = state;
	return newTexture;
}

void	printHelp(const char *binaryName)
{
	std::cerr << "USAGE:" << std::endl
		<< binaryName << " path_to_graphic_library" << std::endl;
}

int	startArcade(char *libraryPath)
{
	std::unique_ptr<Core>	arcade = nullptr;
	int	exit_value = EXIT_SUCCESS;

	try {
		arcade = std::make_unique<Core>(libraryPath);
		arcade->loop();
	} catch (arcade::CoreError const &error) {
		std::cerr << error.what() << std::endl;
		exit_value = 84;
	}
	return (exit_value);
}

int	main(int ac, char **av)
{
	int	exitValue;

	if (ac == 2) {
		exitValue = startArcade(av[1]);
	} else {
		printHelp(av[0]);
		exitValue = 84;
	}
	return exitValue;
}