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
	SfmlDisplay(uint width, uint height);
	~SfmlDisplay() = default;

	public:
	bool	Display();
	bool	BindKey();

	private:
	sf::RenderWindow	*window;
	uint	width;
	uint	height;
};

#endif //CPP_ARCADE_SFML_HPP
