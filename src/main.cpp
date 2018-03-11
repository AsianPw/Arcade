//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstdlib>
#include <iostream>

void	printHelp(const char *binaryName)
{
	std::cerr << "USAGE:" << std::endl
		<< binaryName << " path_to_graphic_library" << std::endl;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
		;//startArcade();
	else
		printHelp(av[0]);
	return (EXIT_SUCCESS);
}