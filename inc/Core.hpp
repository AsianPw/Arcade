/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Core
*/
#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <string>
#include <memory>
#include "IScene.hpp"
#include "Loader.hpp"
#include "GameLoader.hpp"

class Core {
public:
	explicit Core(std::string const &path);
	~Core();
	void	loop();
private:
	void	switchGraphicsLibrary();
	void	switchScene();
private:
	std::unique_ptr<IScene>		scene;
	std::unique_ptr<Loader>		loader;
	std::unique_ptr<GameLoader>	gameLoader;
	std::unique_ptr<IGame>		game;
	IDisplay			*display;
};

#endif //CPP_ARCADE_CORE_HPP
