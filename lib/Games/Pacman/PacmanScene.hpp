//
// EPITECH PROJECT, 2018
// Pacman Scene Game
// File description:
// header file
//

#ifndef PacmanScene_HPP_
# define PacmanScene_HPP_

#include "../../../inc/IScene.hpp"
#include "../../../inc/Texture.hpp"
#include "Pacman.hpp"

static const size_t WIDTH_TEXTURE = 30;
static const size_t HEIGHT_TEXTURE = 30;

typedef enum way_to_go
{
	LEFT,
	RIGHT,
	UP,
	DOWN
}           way_go;

struct Way{
	Position     up = {0, 1};
	Position     left = {-1, 0};
	Position     down = {0, -1};
	Position     right = {1, 0};
	Position     none = {0, 0};
};

class PacmanScene : public IScene {
private:
	std::vector<std::vector<char>> pacmanMap;
	Way                dir;
	Position           gosht;
	Position           move;
	size_t             score;
	Position           player;
	Position           gosht1;
	Position           gosht2;
	Position           gosht3;
	Position           gosht4;
	static const size_t             WIDTH = 26;
	static const size_t             HEIGHT = 20;
	std::map<std::string, Texture>  PacmanTexture;
	std::map<std::string, Texture>  PacmanText;
public:
	PacmanScene();
	~PacmanScene() override = default;
	void    SetCharacters();
	void    sceneEvent(IDisplay *) override ;
	std::map<std::string, Texture>  getTexture() const override ;
	std::map<std::string, Texture>  getText() const override ;
	std::vector<std::vector<char>>  getMap() const override ;
	void    compute() override;
	void    PlayerMove();
	void    createMap();
	void    PlayerEatFood();
	void    GoshtMove();
};

#endif
