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

static const size_t WIDTH_TEXTURE = 27;
static const size_t HEIGHT_TEXTURE = 27;

class PacmanScene : public IScene {
private:
	std::vector<std::vector<char>> pacmanMap;
	size_t             score;
	Position           player;
	Position           gosht1;
	Position           gosht2;
	Position           gosht3;
	Position           gosht4;
	int                direction;
	static const size_t             WIDTH = 26;
	static const size_t             HEIGHT = 20;
	std::map<std::string, Texture>  PacmanTexture;
	std::map<std::string, Texture>  PacmanText;
	long                            currentTime;
	bool                            loose = false;
	bool                            win = false;
	int                             nbr_food;
public:
	PacmanScene();
	~PacmanScene() override = default;
	void    SetCharacters();
	void    sceneEvent(IDisplay *) override ;
	std::map<std::string, Texture>  getTexture() const override ;
	std::map<std::string, Texture>  getText() const override ;
	std::vector<std::vector<char>>  getMap() const override ;
	void    compute() override;
	void    Move_right();
	void    Move_down();
	void    Move_up();
	void    Move_left();
	void    createMap();
	void    GoshtMove();
	void    print_map();
	int     get_nbrfood();
};

#endif