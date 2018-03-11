//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstdlib>
#include <iostream>
#include "../inc/IDisplay.hpp"
#include "../inc/Loader.hpp"

void	printHelp(const char *binaryName)
{
	std::cerr << "USAGE:" << std::endl
		<< binaryName << " path_to_graphic_library" << std::endl;
}

int	startArcade(char *libraryPath)
{
	Loader	*loader = nullptr;
	IDisplay	*display = nullptr;

	if (!checkFileExist(libraryPath))
		return (84);
	loader = new Loader(libraryPath);
	display = loader->create(800, 600);
	while (display->isOpen()) {
		while (display->isKey())
		{
			if (display->GetKey(arcade::WINDOW, arcade::CLOSE))
				display->destroyWindow();
			if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
				display->destroyWindow();
			if (display->GetKey(arcade::KEYBOARD, arcade::UP))
				std::cout << "Arrow Up is pressed !" << std::endl;
			if (display->GetKey(arcade::KEYBOARD, arcade::DOWN))
				std::cout << "Arrow Down is pressed !" << std::endl;
			if (display->GetKey(arcade::KEYBOARD, arcade::LEFT))
				std::cout << "Arrow Left is pressed !" << std::endl;
			if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT))
				std::cout << "Arrow Right is pressed !" << std::endl;
		}
		display->Display();
	}
	loader->destroy(display);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	exitValue = EXIT_SUCCESS;

	printf("%s", av[1]);
	if (ac == 2)
		exitValue = startArcade(av[1]);
	else
		printHelp(av[0]);
	return (exitValue);
}