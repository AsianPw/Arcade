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

class SfmlDisplay : public IDisplay {
public:
	SfmlDisplay(size_t, size_t);
	~SfmlDisplay();
public:
	bool Display();
	bool isOpen();
	bool GetKey(arcade::TypeEvent, std::string const &);
	bool isKey();
	void destroyWindow();
	void setEvent(sf::Event &newEvent);
private:
	std::map<std::string, int> allEvent;
	sf::RenderWindow *window;
	sf::Event event;
	size_t width;
	size_t height;
};

#endif //CPP_ARCADE_SFML_HPP
