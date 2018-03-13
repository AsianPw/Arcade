//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <criterion/criterion.h>
#include <iostream>
#include "../inc/Sfml.hpp"
#include "../inc/Loader.hpp"

Test(SFML_Library, ESCAPE_Key, .description = "Test of KEY_ESCAPE binding")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::KeyPressed;
	tmp.key.code = sf::Keyboard::Escape;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::KEYBOARD, arcade::ESCAPE),
		"Test ESCAPE Key failed !\n");
}

Test(SFML_Library, UP_Key, .description = "Test of KEY_UP binding")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::KeyPressed;
	tmp.key.code = sf::Keyboard::Up;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::KEYBOARD, arcade::UP),
		"Test UP Key failed !\n");
}

Test(SFML_Library, DOWN_Key, .description = "Test of KEY_DOWN binding")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::KeyPressed;
	tmp.key.code = sf::Keyboard::Down;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::KEYBOARD, arcade::DOWN),
		"Test Down Key failed !\n");
}

Test(SFML_Library, CLOSE_Window, .description = "Simulate Close Window")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::WINDOW, arcade::CLOSE),
		"Test Close Window failed !\n");
}

Test(SFML_Library, Check_isKey, .description = "Simulate Close Window")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert(sfml->isKey(), "Test isKey initialize failed !\n");
}


Test(SFML_Library, INVALID_EVENT_TYPE, .description = "Send invalid event type")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert_not(sfml->GetKey(arcade::KEYBOARD, arcade::CLOSE),
		"Send invalid event type failed !\n");
}

Test(SFML_Library, INVALID_KEY_CODE, .description = "Send invalid key code")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));
	sf::Event tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert_not(sfml->GetKey(arcade::WINDOW, "a"),
		"Send invalid key code failed !\n");
}

Test(SFML_Library, isOpen, .description = "Check if window is open")
{
	std::unique_ptr<SfmlDisplay> sfml(new SfmlDisplay(800, 600));

	cr_assert(sfml->isOpen(), "Test window is open failed !\n");
	sfml->Display();
	sfml->destroyWindow();
}

Test(SFML_LIBRARY, Load_SFML_LIBRARY)
{
	std::unique_ptr<Loader> loader(
		new Loader((char *)"./lib/Graphics/Sfml/lsfml_graphic.so"));
	std::unique_ptr<IDisplay> display(loader->create(800, 600));

	cr_assert_not_null(display, "Loading SFML library failed !");
}