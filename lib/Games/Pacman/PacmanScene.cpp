//
// EPITECH PROJECT, 2018
// PacmanScene
// File description:
// source file
//

#include "PacmanScene.hpp"

PacmanScene::PacmanScene() : pacmanMap(HEIGHT, std::vector<char>(WIDTH))
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
			else if (block == 'E')
				PacmanTexture.insert({"gosht" + std::to_string(y) + std::to_string(x), (Texture){"./res/Ghosts_pacman.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'B')
				PacmanTexture.insert({"gosht1", {"./res/blue_gosht.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
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
	pacmanMap[gosht1.x][gosht1.y] = 'E';
	pacmanMap[gosht2.x][gosht2.y] = 'B';
	pacmanMap[gosht3.x][gosht3.y] = 'E';
	pacmanMap[gosht4.x][gosht4.y] = 'E';
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
	if (display->GetKey(arcade::KEYBOARD, arcade::CLOSE)) {
		display->destroyWindow();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE)) {
		display->destroyWindow();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		move = dir.left;
		Move_left();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		move = dir.right;
		Move_right();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::UP)) {
		move = dir.up;
		Move_up();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN)) {
		move = dir.down;
		Move_down();
	}
}

void     PacmanScene::Move_right(void)
{
	int     pos =  PacmanTexture["player"].position.x + WIDTH_TEXTURE;

	PacmanTexture["player"].position.x += WIDTH_TEXTURE;
	PacmanTexture["gosht1"].position.x += WIDTH_TEXTURE;
}

void    PacmanScene::Move_left(void)
{
	PacmanTexture["player"].position.x -= WIDTH_TEXTURE;
	PacmanTexture["gosht1"].position.x -= WIDTH_TEXTURE;
}

void    PacmanScene::Move_up(void)
{
	PacmanTexture["player"].position.y -= HEIGHT_TEXTURE;
	PacmanTexture["gosht1"].position.y -= HEIGHT_TEXTURE;
}

void    PacmanScene::Move_down(void)
{
	PacmanTexture["player"].position.y += HEIGHT_TEXTURE;
	PacmanTexture["gosht1"].position.y -= HEIGHT_TEXTURE;
}

void     PacmanScene::PlayerEatFood(void)
{
	// TO DO ACTION OF PALYER'S EATING //
}

void    PacmanScene::GoshtMove(void)
{
	// TO DO MOVEMENT OF GOSHTS //
	int  d;

	d = rand()%(3) + 1 - 1;
	if (d == 0)
		PacmanTexture["gosht1"].position.x -= WIDTH_TEXTURE;
	else if (d == 1)
		PacmanTexture["gosht1"].position.x += WIDTH_TEXTURE;
	else if (d == 2)
		PacmanTexture["gosht1"].position.y -= HEIGHT_TEXTURE;
	else if (d == 3)
		PacmanTexture["gosht1"].position.y += HEIGHT_TEXTURE;
}

void    PacmanScene::compute(void)
{
	// TO DO ia of the goshts //
	//srand(time(NULL));
	//GoshtMove();
}

void    PacmanScene::createMap(void)
{
	pacmanMap.resize(WIDTH, std::vector<char>(HEIGHT));
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
