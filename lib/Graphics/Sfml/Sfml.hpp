//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Definition of SFML Class
//

#ifndef CPP_ARCADE_SFML_HPP
#	define CPP_ARCADE_SFML_HPP

#	include <SFML/Graphics.hpp>
#	include "../../../inc/IDisplay.hpp"

class SfmlDisplay : public IDisplay {
public:
	SfmlDisplay(size_t, size_t);
	~SfmlDisplay() override;
public:
	bool Display() override;
	bool isOpen() override;
	bool GetKey(arcade::TypeEvent, std::string const &) override;
	bool isKey() override;
	void destroyWindow() override;
	void setEvent(sf::Event &newEvent);
private:
	size_t width;
	size_t height;
	std::map<std::string, int> allEvent;
	sf::RenderWindow *window;
	sf::Event event;
};

#endif //CPP_ARCADE_SFML_HPP
