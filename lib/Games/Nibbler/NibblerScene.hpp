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
	Position	up = {1, 0};
	Position	left = {0, -1};
	Position	down = {-1, 0};
	Position	right = {0, 1};
};

static const size_t WIDTH_TEXTURE = 20;
static const size_t HEIGHT_TEXTURE = 20;

class NibblerScene : public IScene{
public:
	NibblerScene();
	~NibblerScene() = default;
	void	sceneEvent(IDisplay *) override ;
	std::map<std::string, Texture>	getTexture() const override ;
	std::map<std::string, Texture>	getText() const override ;
	void	compute() override;
	int	eatAndGrow();
	void	snakeMove();
	void	createCandy();
	void	createMap();

private:
	std::map<std::string, Texture>	nibblerTexture;
	std::map<std::string, Texture>	nibblerText;
	std::vector<Position>		nibblerBody;
	std::vector<std::vector<char>>	nibblerMap;
	size_t				score;
	Direction			direction;
	Position			move;
	Position			candy;
	static const size_t		WIDTH = 20;
	static const size_t		HEIGHT = 10;
};

#endif //CPP_ARCADE_NIBBLERSCENE_HPP
