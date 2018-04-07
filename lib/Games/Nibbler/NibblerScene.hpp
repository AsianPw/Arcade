//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// NibblerScene.hpp
//

#ifndef CPP_ARCADE_NIBBLERSCENE_HPP
#define CPP_ARCADE_NIBBLERSCENE_HPP

#include "../../../inc/IScene.hpp"
#include "../../../inc/Texture.hpp"
#include "Nibbler.hpp"

struct	Direction {
	Position	up = {0, -1};
	Position	left = {-1, 0};
	Position	down = {0, 1};
	Position	right = {1, 0};
};

static const size_t WIDTH_TEXTURE = 20;
static const size_t HEIGHT_TEXTURE = 20;

class NibblerScene : public IScene{
public:
	NibblerScene();
	~NibblerScene() override = default;
	void	sceneEvent(IDisplay *) override ;
	std::map<std::string, Texture>	getTexture() const override ;
	std::map<std::string, Texture>	getText() const override ;
	void	compute() override;
	int	eatAndGrow();

	std::vector<std::vector<char>> getMap() const override;

	void	showMap();
	void	snakeMove();
	void	createCandy();
	void	createMap();
	void	createSnake();

private:
	int				timer;
	std::map<std::string, Texture>	nibblerTexture;
	std::map<std::string, Texture>	nibblerText;
	std::vector<Position>		nibblerBody;
	std::vector<std::vector<char>>	nibblerMap;
	size_t				score;
	Direction			direction;
	Position			move;
	Position			candy;
	static const int		WIDTH = 30;
	static const int		HEIGHT = 20;
};

#endif //CPP_ARCADE_NIBBLERSCENE_HPP
