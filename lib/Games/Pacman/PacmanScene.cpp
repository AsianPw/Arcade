//
// EPITECH PROJECT, 2018
// PacmanScene
// File description:
// source file
//

#include "PacmanScene.hpp"
#include <chrono>
#include <iostream>
#include "../../../inc/Time.hpp"

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
	score = 0;
	nbr_food = get_nbrfood();
	PacmanText.insert({"score_value", {std::to_string(score), ' ', false, true, {240, 550}}});
	PacmanText.insert({"title", {"Score :", ' ', false, true, {100, 550}}});
	PacmanText.insert({"food_value", {std::to_string(nbr_food), ' ', false, true, {620, 550}}});
	PacmanText.insert({"title_food", {"Remaining food :", ' ', false, true, {350, 550}}});
	for (auto const &line : pacmanMap) {
		x = 0;
		for (auto const &block : line) {
			if (block == '*')
				PacmanTexture.insert({"wall" + std::to_string(y) + std::to_string(x), (Texture){"./res/wall_nibbler.png", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
			else if (block == 'G')
				PacmanTexture.insert({"player", {"./res/pacman_right.jpg", ' ',  true, true, {(int)(x * WIDTH_TEXTURE), (int)(y * HEIGHT_TEXTURE)}}});
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
	if (display->GetKey(arcade::KEYBOARD, arcade::CLOSE)) {
		display->destroyWindow();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::ESCAPE)) {
		display->destroyWindow();
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::LEFT)) {
		if (loose == true || win == true)
			exit(0);
		if (pacmanMap[player.x][player.y - 1] == '*')
			return;
		if (pacmanMap[player.x][player.y - 1] == 'o') {
			score += 10;
			nbr_food--;
			PacmanTexture.erase("food" + std::to_string(player.x) + std::to_string(player.y - 1));
			PacmanText["score_value"].path = std::to_string(score);
			PacmanText["food_value"].path = std::to_string(nbr_food);
		}
                player.y--;
		Move_left();
		PacmanTexture.erase("player");
		PacmanTexture.insert({"player", {"./res/pacman_left.jpg", ' ',  true, true, {(int)(player.y * WIDTH_TEXTURE), (int)(player.x * HEIGHT_TEXTURE)}}});
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::RIGHT)) {
		if (loose == true || win == true)
			exit(0);
		if (pacmanMap[player.x][player.y + 1] == '*')
			return;
		if (pacmanMap[player.x][player.y + 1] == 'o') {
			score += 10;
			nbr_food--;
			PacmanTexture.erase("food" + std::to_string(player.x) + std::to_string(player.y + 1));
			PacmanText["score_value"].path = std::to_string(score);
			PacmanText["food_value"].path = std::to_string(nbr_food);
		}
		player.y++;
		Move_right();
		PacmanTexture.erase("player");
		PacmanTexture.insert({"player", {"./res/pacman_right.jpg", ' ',  true, true, {(int)(player.y * WIDTH_TEXTURE), (int)(player.x * HEIGHT_TEXTURE)}}});
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::UP)) {
		if (loose == true || win == true)
			exit(0);
		if (pacmanMap[player.x - 1][player.y] == '*')
			return;
		if (pacmanMap[player.x - 1][player.y] == 'o') {
			score += 10;
			nbr_food--;
			PacmanTexture.erase("food" + std::to_string(player.x - 1) + std::to_string(player.y));
			PacmanText["score_value"].path = std::to_string(score);
			PacmanText["food_value"].path = std::to_string(nbr_food);
		}
		player.x--;
		Move_up();
		PacmanTexture.erase("player");
		PacmanTexture.insert({"player", {"./res/pacman_up.jpg", ' ',  true, true, {(int)(player.y * WIDTH_TEXTURE), (int)(player.x * HEIGHT_TEXTURE)}}});
	}
	if (display->GetKey(arcade::KEYBOARD, arcade::DOWN)) {
		if (loose == true || win == true)
			exit(0);
		if (pacmanMap[player.x + 1][player.y] == '*' || player.x > 20)
			return;
		if (pacmanMap[player.x + 1][player.y] == 'o') {
			score += 10;
			nbr_food--;
			PacmanTexture.erase("food" + std::to_string(player.x + 1) + std::to_string(player.y));
			PacmanText["score_value"].path = std::to_string(score);
			PacmanText["food_value"].path = std::to_string(nbr_food);
		}
		player.x++;
		Move_down();
		PacmanTexture.erase("player");
		PacmanTexture.insert({"player", {"./res/pacman_down.jpg", ' ',  true, true, {(int)(player.y * WIDTH_TEXTURE), (int)(player.x * HEIGHT_TEXTURE)}}});
	}
}

void     PacmanScene::Move_right(void)
{
	PacmanTexture["player"].position.x += WIDTH_TEXTURE;
	if (pacmanMap[player.x][player.y] == 'A' || pacmanMap[player.x][player.y] == 'B' \
	    || pacmanMap[player.x][player.y] == 'C' || pacmanMap[player.x][player.y] == 'D') {
		PacmanText.insert({"lost", {"Game Over", ' ', false, true, {300, 280}}});
		loose = true;
	}
	if (nbr_food == 0) {
		PacmanText.insert({"lost", {"You Won", ' ', false, true, {300, 280}}});
		win = true;
	}
	pacmanMap[player.x][player.y] = ' ';
	print_map();
}

void    PacmanScene::Move_left(void)
{
	PacmanTexture["player"].position.x -= WIDTH_TEXTURE;
	if (pacmanMap[player.x][player.y] == 'A' || pacmanMap[player.x][player.y] == 'B' \
	    || pacmanMap[player.x][player.y] == 'C' || pacmanMap[player.x][player.y] == 'D') {
		PacmanText.insert({"lost", {"Game Over", ' ', false, true, {300, 280}}});
		loose = true;
	}
	if (nbr_food == 0) {
		PacmanText.insert({"lost", {"You Won", ' ', false, true, {300, 280}}});
		win = true;
	}
	pacmanMap[player.x][player.y] = ' ';
	print_map();
}

void    PacmanScene::Move_up(void)
{
	PacmanTexture["player"].position.y -= HEIGHT_TEXTURE;
	if (pacmanMap[player.x][player.y] == 'A' || pacmanMap[player.x][player.y] == 'B' \
	    || pacmanMap[player.x][player.y] == 'C' || pacmanMap[player.x][player.y] == 'D') {
		PacmanText.insert({"lost", {"Game Over", ' ', false, true, {300, 280}}});
		loose = true;
	}
	if (nbr_food == 0) {
		PacmanText.insert({"lost", {"You Won", ' ', false, true, {300, 280}}});
		win = true;
	}
	pacmanMap[player.x][player.y] = ' ';
	print_map();
}

void    PacmanScene::Move_down(void)
{
	PacmanTexture["player"].position.y += HEIGHT_TEXTURE;
	if (pacmanMap[player.x][player.y] == 'A' || pacmanMap[player.x][player.y] == 'B' \
	    || pacmanMap[player.x][player.y] == 'C' || pacmanMap[player.x][player.y] == 'D') {
		PacmanText.insert({"lost", {"Game Over", ' ', false, true, {300, 280}}});
		loose = true;
        }
	if (nbr_food == 0) {
		PacmanText.insert({"lost", {"You Won", ' ', false, true, {300, 280}}});
		win = true;
	}
	pacmanMap[player.x][player.y] = ' ';
	print_map();
}

int    PacmanScene::get_nbrfood(void)
{
	nbr_food = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 26; j++) {
			if (pacmanMap[i][j] == 'o')
				nbr_food++;
		}
	}
	return (nbr_food);
}

void    PacmanScene::GoshtMove(void)
{
	int d = rand()%3;

	if (d == 0) {
		PacmanTexture["gosht3"].position.x -= WIDTH_TEXTURE;
	}
	else if (d == 1) {
		PacmanTexture["gosht3"].position.x += WIDTH_TEXTURE;
	}
	else if (d == 2) {
		PacmanTexture["gosht3"].position.y -= HEIGHT_TEXTURE;
	}
	else if (d == 3) {
		PacmanTexture["gosht3"].position.y += HEIGHT_TEXTURE;
	}
}

void    PacmanScene::compute(void)
{
	long    now = getCurrentTime();

	if (now - currentTime > 250) {
		GoshtMove();
		currentTime = now;
	}
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
