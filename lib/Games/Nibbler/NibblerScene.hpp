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
	Position	up = {5, 0};
	Position	left = {0, -5};
	Position	down = {-5, 0};
	Position	right = {0, 5};
};

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

private:
	std::map<std::string, Texture>	nibblerTexture;
	std::map<std::string, Texture>	nibblerText;
	std::vector<Position>	nibblerBody;
	size_t			score;
	Position		move;
	Position		candy;
};

#endif //CPP_ARCADE_NIBBLERSCENE_HPP
