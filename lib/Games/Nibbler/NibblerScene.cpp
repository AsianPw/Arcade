//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// NibblerScene.cpp
//

#include <iostream>
#include <unistd.h>
#include "NibblerScene.hpp"

NibblerScene::NibblerScene() : nibblerMap(HEIGHT, std::vector<char>(WIDTH)), move(direction.right), nibblerBody(4)
{
	size_t	x;
	size_t	y = 5;

	candy = {25, 9};
	createSnake();
	createMap();
	for (auto const &line : nibblerMap) {
		x = 5;
		for (auto const &block : line) {
			if (block == '#')
				nibblerTexture.insert({"block" + std::to_string(y) + std::to_string(x), (Texture){"./res/wall_nibbler.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == '@')
				nibblerTexture.insert({"candy", (Texture){"./res/candy_nibbler.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'O')
				nibblerTexture.insert({"nibbler" + std::to_string(y) + std::to_string(x), (Texture){"./res/nibbler.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			x++;
		}
		y++;
	}
}

void	NibblerScene::createSnake()
{
	nibblerBody[0] = {6, 9};
	nibblerBody[1] = {5, 9};
	nibblerBody[2] = {4, 9};
	nibblerBody[3] = {3, 9};
}

void	NibblerScene::createMap()
{
	int 	x = 0;
	int	y = 0;

	//nibblerMap.resize(WIDTH, std::vector<char>(HEIGHT));
	while (y < HEIGHT) {
		x = 0;
		while (x < WIDTH) {
			if (y == 0 || y == HEIGHT-1 || x == 0 || x == WIDTH-1)
				nibblerMap[y][x] = '#';
			else if (x == candy.x && y == candy.y)
				nibblerMap[y][x] = '@';
			else if ((x == 5 || x == 6 || x == 4 || x == 3) && y == 9)
			{
				nibblerMap[y][x] = 'O';
			}
			else
				nibblerMap[y][x] = ' ';
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
	nibblerBody.resize(nibblerBody.size()+1);
	nibblerBody.emplace_back(lastPos);
	createCandy();
	return (0);
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
	nibblerTexture["candy"].position.x -= HEIGHT_TEXTURE;
}

std::vector<std::vector<char>> NibblerScene::getMap() const
{
	return nibblerMap;
}
