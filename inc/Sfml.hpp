//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Definition of SFML Class
//

#ifndef CPP_ARCADE_SFML_HPP
#	define CPP_ARCADE_SFML_HPP

#	include <SFML/Graphics.hpp>
#	include "IDisplay.hpp"

class SfmlDisplay : public IDisplay
{
	public:
	SfmlDisplay(unsigned int width, unsigned int height);
	~SfmlDisplay();

	public:
	bool	Display();
	bool	isOpen();
	bool	GetKey(arcade::TypeEvent typeEvent, char *event);
	bool	isKey();
	void	destroyWindow();

	public:
	std::map<std::string, int>	allEvent;

	private:
	sf::RenderWindow	*window;
	sf::Event		event;
	uint	width;
	uint	height;
};

#endif //CPP_ARCADE_SFML_HPP
