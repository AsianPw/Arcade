//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstdlib>
#include <iostream>
#include <dlfcn.h>
#include "../inc/IDisplay.hpp"

void	printHelp(const char *binaryName)
{
	std::cerr << "USAGE:" << std::endl
		<< binaryName << " path_to_graphic_library" << std::endl;
}

int	startArcade(char *libraryPath)
{
	void	*handle = dlopen(libraryPath, RTLD_LAZY);

	IDisplay* (*create)(unsigned int, unsigned int);
	void (*destroy)(IDisplay*);

	create = (IDisplay* (*)(unsigned int, unsigned int))dlsym(handle, "create_object");
	destroy = (void (*)(IDisplay*))dlsym(handle, "destroy_object");

	auto myClass = create(800, 600);
	while (myClass->isOpen()) {
		while (myClass->isKey())
		{
			if (myClass->GetKey(arcade::WINDOW, arcade::CLOSE))
				myClass->destroyWindow();
			if (myClass->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
				myClass->destroyWindow();
		}
		myClass->Display();
	}
	destroy(myClass);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	exitValue = EXIT_SUCCESS;

	if (ac == 2)
		exitValue = startArcade(av[1]);
	else
		printHelp(av[0]);
	return (exitValue);
}