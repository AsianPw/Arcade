//
// EPITECH PROJECT, 2018
// PacmanScene
// File description:
// source file
//

#include "PacmanScene.hpp"
#include <ctime>
#include <unistd.h>
#include <iostream>

void PacmanScene::print_map()
{
	std::cout<<"*******************************************************"<<std::endl;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 26; j++)
			std::cout<<pacmanMap[i][j];
	std::cout<<"*******************************************************"<<std::endl;
}

PacmanScene::PacmanScene() : pacmanMap(WIDTH, std::vector<char>(HEIGHT))
{
	size_t  x = 0;
	size_t  y = 0;

	createMap();
	SetCharacters();
	for (auto const &line : pacmanMap) {
		x = 0;
		for (auto const &block : line) {
			if (block == '*')
				PacmanTexture.insert({"wall" + std::to_string(y) + std::to_string(x), (Texture){"./res/wall_nibbler.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'G')
				PacmanTexture.insert({"player", {"./res/player_pacman.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'o')
				PacmanTexture.insert({"food" + std::to_string(y) + std::to_string(x), (Texture){"./res/food_pacman.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'A')
				PacmanTexture.insert({"gosht1" + std::to_string(y) + std::to_string(x), (Texture){"./res/Ghosts_pacman.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'B')
				PacmanTexture.insert({"gosht2", {"./res/blue_gosht.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'C')
				PacmanTexture.insert({"gosht3", {"./res/Ghosts_pacman1.png", ' ', true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'D')
                                PacmanTexture.insert({"gosht4", {"./res/Ghosts_pacman2.png", ' ', true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			x = x + 1;
		}
		y = y + 1;
	}
}

void    PacmanScene::SetCharacters(void)
{
	player.x = 8;
	player.y = 13;
	gosht1.x = 9;
	gosht1.y = 12;
	gosht2.x = 9;
	gosht2.y = 13;
	gosht3.x = 10;
	gosht3.y = 12;
	gosht4.x = 10;
	gosht4.y = 13;
	pacmanMap[gosht1.x][gosht1.y] = 'A';
	pacmanMap[gosht2.x][gosht2.y] = 'B';
	pacmanMap[gosht3.x][gosht3.y] = 'C';
	pacmanMap[gosht4.x][gosht4.y] = 'D';
	pacmanMap[player.x][player.y] = 'G';
}

std::map<std::string, Texture>  PacmanScene::getTexture() const
{
	return PacmanTexture;
}

std::map<std::string, Texture>  PacmanScene::getText() const
{
	return PacmanText;
}

void    PacmanScene::sceneEvent(IDisplay *display)
{
	if (display->GetKey(arcade::WINDOW, arcade::CLOSE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::Q))
		display->destroyWindow();
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		if (pacmanMap[player.x][player.y - 1] == '*')
			return;
		pacmanMap[player.x][player.y] = ' ';
                player.y--;
		move = dir.left;
		Move_left();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		if (pacmanMap[player.x][player.y + 1] == '*')
			return;
		pacmanMap[player.x][player.y] = ' ';
		player.y++;
		move = dir.right;
		Move_right();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::UP)) {
		if (pacmanMap[player.x - 1][player.y] == '*')
			return;
		pacmanMap[player.x][player.y] = ' ';
		player.x--;
		move = dir.up;
		Move_up();

	}
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN)) {
		if (pacmanMap[player.x + 1][player.y] == '*' || player.x > 20)
			return;
		pacmanMap[player.x][player.y] = ' ';
		player.x++;
		move = dir.down;
		Move_down();
	}
}

void     PacmanScene::Move_right(void)
{
	PacmanTexture["player"].position.x += WIDTH_TEXTURE;
	print_map();
}

void    PacmanScene::Move_left(void)
{
	PacmanTexture["player"].position.x -= WIDTH_TEXTURE;
	print_map();
}

void    PacmanScene::Move_up(void)
{
	PacmanTexture["player"].position.y -= HEIGHT_TEXTURE;
	print_map();
}

void    PacmanScene::Move_down(void)
{
	PacmanTexture["player"].position.y += HEIGHT_TEXTURE;
	print_map();
}

void     PacmanScene::PlayerEatFood(void)
{
	// TO DO ACTION OF PALYER'S EATING //
}

void    PacmanScene::GoshtMove(void)
{
	// TO DO MOVEMENT OF GOSHTS //
	int  d;

	srand(time(NULL));
	d = rand()%(3) + 1 - 1;
	if (d == 0) {
		PacmanTexture["gosht1"].position.x -= WIDTH_TEXTURE;
		PacmanTexture["gosht3"].position.x -= WIDTH_TEXTURE;
		PacmanTexture["gosht4"].position.x -= WIDTH_TEXTURE;
	}
	else if (d == 1) {
		PacmanTexture["gosht1"].position.x += WIDTH_TEXTURE;
		PacmanTexture["gosht3"].position.x += WIDTH_TEXTURE;
		PacmanTexture["gosht4"].position.x += WIDTH_TEXTURE;
	}
	else if (d == 2) {
		PacmanTexture["gosht1"].position.y -= HEIGHT_TEXTURE;
		PacmanTexture["gosht3"].position.y -= HEIGHT_TEXTURE;
		PacmanTexture["gosht4"].position.y -= HEIGHT_TEXTURE;
	}
	else if (d == 3) {
		PacmanTexture["gosht1"].position.y += HEIGHT_TEXTURE;
		PacmanTexture["gosht3"].position.y += HEIGHT_TEXTURE;
		PacmanTexture["gosht4"].position.y += HEIGHT_TEXTURE;
	}
}

void    PacmanScene::compute(void)
{
	// TO DO ia of the goshts //
	GoshtMove();
}

void    PacmanScene::createMap(void)
{
	pacmanMap.resize(HEIGHT, std::vector<char>(WIDTH));
	pacmanMap = {{'\n','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
		     {'\n','*','o','o','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','o','o','*'},
		     {'\n','*','o','o','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','o','o','*'},
		     {'\n','*','o','o','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','o','o','*'},
		     {'\n','*','o','o','*','o','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','o','*','o','o','*'},
		     {'\n','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*'},
		     {'\n','*','o','*','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','*','o','*'},
		     {'\n','*','o','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','o','*'},
		     {'\n','*','o','*','o','o','*','*','o','*','*','*',' ',' ',' ','*','*','*','o','o','*','*','o','*','o','*'},
		     {'\n','*','o','o','o','o','o','o','o','*',' ',' ',' ',' ',' ',' ',' ','*','o','o','o','o','o','o','o','*'},
		     {'\n','*','o','o','o','o','o','o','o','*',' ',' ',' ',' ',' ',' ',' ','*','o','o','o','o','o','o','o','*'},
		     {'\n','*','o','o','o','o','o','o','o','*',' ',' ',' ',' ',' ',' ',' ','*','o','o','o','o','o','o','o','*'},
		     {'\n','*','o','*','o','o','*','*','o','*','*','*','*','*','*','*','*','*','o','o','*','*','o','*','o','*'},
		     {'\n','*','o','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','o','*'},
		     {'\n','*','o','*','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','*','o','*'},
		     {'\n','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*'},
		     {'\n','*','o','o','*','o','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','o','*','o','o','*'},
		     {'\n','*','o','o','*','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','*','o','o','*'},
		     {'\n','*','o','o','*','o','o','o','o','o','o',' ','o','o','o','o','o','o','o','o','o','o','*','o','o','*'},
		     {'\n','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}};
}

std::vector<std::vector<char>>   PacmanScene::getMap() const
{
	return pacmanMap;
}
