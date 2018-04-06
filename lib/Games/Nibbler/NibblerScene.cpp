//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// NibblerScene.cpp
//

#include <iostream>
#include "NibblerScene.hpp"

NibblerScene::NibblerScene() : nibblerMap(HEIGHT, std::vector<char>(WIDTH)), move(direction.right)
{
	size_t	x = 0;
	size_t	y = 0;

	candy = {15, 5};
	for (auto const &line : nibblerMap) {
		y = 0;
		for (auto const &block : line) {
			if (block == '#')
				nibblerTexture.insert({"block" + std::to_string(42), createTexture("./res/wall_nibbler.png",true, x * WIDTH_TEXTURE, y * HEIGHT_TEXTURE)});
			else if (block == '@')
				nibblerTexture.insert({"candy", createTexture("./res/candy_nibbler.png",true, x * WIDTH_TEXTURE, y * HEIGHT_TEXTURE)});
			x++;
		}
		y++;
	}
}

void	NibblerScene::createMap()
{
	size_t	x = 0;
	size_t	y = 0;

	while (y <= HEIGHT) {
		x = 0;
		while (x <= WIDTH) {
			if (y == 0 || y == HEIGHT || x == 0 || x == WIDTH)
				nibblerMap[y][x] = '#';
			else if (x == candy.x && y == candy.y)
				nibblerMap[y][x] = '@';
			x++;
		}
		y++;
	}
}

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
	if (display->GetKey(arcade::KEYBOARD, arcade::CLOSE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		if (&move == &direction.right || &move == &direction.left)
			return;
		else
			move = direction.left;
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		if (&move == &direction.right || &move == &direction.left)
			return;
		else
			move = direction.right;
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::UP)) {
		if (&move == &direction.up || &move == &direction.down)
			return;
		else
			move = direction.up;
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN)) {
		if (&move == &direction.up || &move == &direction.down)
			return;
		else
			move = direction.down;
	}
}

std::map<std::string, Texture>	NibblerScene::getTexture() const {
	return nibblerTexture;
}

std::map<std::string, Texture>	NibblerScene::getText() const {
	return nibblerText;
}

void	NibblerScene::compute()
{
	auto	it = nibblerBody.begin();

	if ((it->x + move.x) != candy.x && (it->y + move.y) != candy.y)
		snakeMove();
	else if ((it->x + move.x) == candy.x && (it->y + move.y) == candy.y)
		eatAndGrow();
}