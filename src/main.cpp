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
#include "Menu.hpp"
#include "../inc/GameLoader.hpp"

Texture	createTexture(std::string path, bool state, int x, int y)
{
	Texture	newTexture;

	newTexture.isFile = checkFileExist(path);
	newTexture.position = {x,y};
	newTexture.path = path;
	newTexture.display = state;
	return newTexture;
}

void	printHelp(const char *binaryName)
{
	std::cerr << "USAGE:" << std::endl
		<< binaryName << " path_to_graphic_library" << std::endl;
}

IDisplay	*switchLibrary(std::unique_ptr<Loader> &loader, IDisplay *display)
{
	std::string	tmpPath = arcade::GRAPHICSDIR + display->getLibraryPath();

	display->setChange(false);
	if (display->getLibraryPath().empty())
		return display;
	if (display->isOpen())
		display->destroyWindow();
	loader->destroy(display);
	try {
		loader.reset(new Loader(tmpPath));
	} catch (arcade::LoaderError const& e) {
		std::cerr << e.what() << std::endl;
	}
	return loader->create(arcade::WIDTH, arcade::HEIGHT);
}

void	switchScene(IDisplay *display, std::unique_ptr<IScene> &scene, std::unique_ptr<GameLoader> &gameLoader, std::unique_ptr<IGame>	&game)
{
	display->setSwitchScene(false);
	if (display->getNewGamePath() == "menu") {
		gameLoader = nullptr;
		scene.reset(new Menu());
	}
	try {
		gameLoader.reset(new GameLoader(display->getNewGamePath()));
	} catch (arcade::LoaderError const& e) {
		std::cerr << e.what() << std::endl;
		gameLoader = nullptr;
		return;
	}
	game.reset(gameLoader->create());
	scene.reset(game->start());
}

int	startArcade(char *libraryPath)
{
	std::unique_ptr<IScene>	scene = nullptr;
	std::unique_ptr<Loader>	loader = nullptr;
	std::unique_ptr<GameLoader>	gameLoader = nullptr;
	std::unique_ptr<IGame>		game = nullptr;
	IDisplay		*display = nullptr;

	scene = std::make_unique<Menu>();
	try {
		loader = std::make_unique<Loader>(libraryPath);
	} catch (arcade::LoaderError const& e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
	display = loader->create(arcade::WIDTH, arcade::HEIGHT);
	while (display->isOpen()) {
		while (display->isKey())
			scene->sceneEvent(display);
		if (display->getChange())
			display = switchLibrary(loader, display);
		if (display->getSwitchScene()) {
			switchScene(display, scene, gameLoader, game);
		}
		scene->compute();
		display->loadTexture(scene->getTexture());
		display->loadText(scene->getText());
		display->Display();
	}
	scene.reset();
	if (gameLoader != nullptr)
		gameLoader->destroy(game.release());
	loader->destroy(display);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	exitValue = EXIT_SUCCESS;

	if (ac == 2) {
		exitValue = startArcade(av[1]);
	} else {
		printHelp(av[0]);
	}
	return exitValue;
}