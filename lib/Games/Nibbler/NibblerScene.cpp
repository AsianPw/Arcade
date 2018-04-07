//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// NibblerScene.cpp
//

#include <iostream>
#include <chrono>
#include "../../../src/Time.hpp"
#include "NibblerScene.hpp"

NibblerScene::NibblerScene() : nibblerBody(4), nibblerMap(HEIGHT, std::vector<char>(WIDTH)), move(direction.right)
{
	timer = 0;
	candy = {25, 9};
	createSnake();
	createMap();
	showMap();
}

void	NibblerScene::showMap()
{
	size_t	x;
	size_t	y = 5;

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
	auto	it = nibblerBody.begin();
	bool	state;

	while (y < HEIGHT) {
		x = 0;
		while (x < WIDTH) {
			state = false;
			while (it != nibblerBody.end())
			{
				if (x == it->x && y == it->y)
				{
					nibblerMap[y][x] = 'O';
					state = true;
				}
				it++;
			}
			if (y == 0 || y == HEIGHT-1 || x == 0 || x == WIDTH-1)
				nibblerMap[y][x] = '#';
			else if (x == candy.x && y == candy.y)
				nibblerMap[y][x] = '@';
			else if (!state)
				nibblerMap[y][x] = ' ';
			x++;
			it = nibblerBody.begin();
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
	int	x = rand() % WIDTH;
	int	y = rand() % HEIGHT;

	if (nibblerMap[y][x] != '#' && nibblerMap[y][x] != 'O') {
		candy.y = y;
		candy.x = x;
	}
}

void	NibblerScene::sceneEvent(IDisplay *display)
{
	if (display->GetKey(arcade::KEYBOARD, arcade::CLOSE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		if (move.x == direction.right.x || move.x == direction.left.x)
			return;
		else
			move = direction.left;
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		if (move.x == direction.right.x || move.x == direction.left.x)
			return;
		else
			move = direction.right;
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::UP)) {
		if (move.y == direction.up.y || move.y == direction.down.y)
			return;
		else
			move = direction.up;
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN)) {
		if (move.y == direction.up.y || move.y == direction.down.y)
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
	long	now = getCurrentTime();
	int x = (nibblerTexture["candy"].position.x)/20-5;
	int y = (nibblerTexture["candy"].position.y)/20-5;
	if (timer > 30) {
		if (nibblerMap[y + move.y][x + move.x] == '#')
			exit(84);
		nibblerTexture["candy"].position.x += move.x * 20;
		nibblerTexture["candy"].position.y += move.y * 20;
		timer = 0;
	}
	timer++;
}

std::vector<std::vector<char>> NibblerScene::getMap() const
{
	return nibblerMap;
}
