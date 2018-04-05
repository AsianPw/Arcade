//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// NibblerScene.cpp
//

#include "NibblerScene.hpp"

NibblerScene::NibblerScene()
{
};

NibblerScene::~NibblerScene()
{

};

void	NibblerScene::snakeMove()
{
	auto	it = nibblerBody.end();

	while (it != nibblerBody.begin())
	{
		it->x = --it->x;
		it->y = --it->y;
		it--;
	}
	it = nibblerBody.begin();
	it->x += move.x;
	it->y += move.y;
}

int	NibblerScene::eatAndGrow() {
	auto		it = nibblerBody.end();
	Position	lastPos = {it->x, it->y};

	score++;
	snakeMove();
	nibblerBody.emplace_back(lastPos);
	createCandy();
}

void	NibblerScene::createCandy()
{
	candy.y = 10;
	candy.x = 10;
}

void	NibblerScene::sceneEvent(IDisplay *display)
{
	if (display->GetKey(arcade::KEYBOARD, arcade::CLOSE)) {
		display->destroyWindow();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE)) {

	}
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		//turn_left
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		//turn_right
	}
};

std::map<std::string, Texture>	NibblerScene::getTexture() const {
	return nibblerTexture;
};

std::map<std::string, Texture>	NibblerScene::getText() const {
	return nibblerText;
};

void	NibblerScene::compute()
{
	auto	it = nibblerBody.begin();

	if ((it->x + move.x) != candy.x && (it->y + move.y) != candy.y)
		snakeMove();
	else if ((it->x + move.x) == candy.x && (it->y + move.y) == candy.y)
		eatAndGrow();
};