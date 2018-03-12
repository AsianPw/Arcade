//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <criterion/criterion.h>
#include <iostream>
#include "../inc/utils.hpp"
#include "../inc/Sfml.hpp"

ReportHook(PRE_SUITE)(struct criterion_suite_set *suite_set) {
	std::cout << suite_set->suite.name << " suite:" << std::endl;
}

ReportHook(PRE_TEST)(struct criterion_test *test) {
	std::cout << "Begin of " << test->name << ":\t" << test->data->description << std::endl;
}

ReportHook(POST_TEST)(struct criterion_test_stats *stats) {
	std::cout << "\tTest elapsed:" << stats->elapsed_time << std::endl;
}

ReportHook(POST_SUITE)(struct criterion_suite_stats *stats) {
	std::cout << stats->suite->name << " is Finish" << std::endl;
}

Test(Generate, framebuffer, .description = "Check if framebuffer is correctly allocate")
{
	std::vector<uint8_t>	*tmp = createFramebuffer(800, 600, 4);
	cr_assert(tmp->size() == (800 * 600 * 4), "Test if size of framebuffer is good\n");
}

Test(Generate, framebuffer_bad_alloc, .description = "Test of big framebuffer allocation")
{
	cr_assert_any_throw(createFramebuffer(((size_t)~0), 100000, 4), "Exception doesn't catch\n");
}

Test(SFML_Library, ESCAPE_Key, .description = "Test of KEY_ESCAPE binding")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::KeyPressed;
	tmp.key.code = sf::Keyboard::Escape;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::KEYBOARD, arcade::ESCAPE), "Test ESCAPE Key failed !\n");
}

Test(SFML_Library, UP_Key, .description = "Test of KEY_UP binding")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::KeyPressed;
	tmp.key.code = sf::Keyboard::Up;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::KEYBOARD, arcade::UP), "Test UP Key failed !\n");
}

Test(SFML_Library, DOWN_Key, .description = "Test of KEY_DOWN binding")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::KeyPressed;
	tmp.key.code = sf::Keyboard::Down;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::KEYBOARD, arcade::DOWN), "Test Down Key failed !\n");
}

Test(SFML_Library, CLOSE_Window, .description = "Simulate Close Window")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert(sfml->GetKey(arcade::WINDOW, arcade::CLOSE), "Test Close Window failed !\n");
}

Test(SFML_Library, Check_isKey, .description = "Simulate Close Window")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert(sfml->isKey(), "Test isKey initialize failed !\n");
}


Test(SFML_Library, INVALID_EVENT_TYPE, .description = "Send invalid event type")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert_not(sfml->GetKey(arcade::KEYBOARD, arcade::CLOSE), "Test Close Window failed !\n");
}

Test(SFML_Library, INVALID_KEY_CODE, .description = "Send invalid key code")
{
	auto	sfml = new SfmlDisplay(800, 600);
	sf::Event	tmp;

	tmp.type = sf::Event::Closed;
	sfml->setEvent(tmp);
	cr_assert_not(sfml->GetKey(arcade::WINDOW, "a"), "Test Close Window failed !\n");
}

Test(SFML_Library, isOpen, .description = "Check if window is open")
{
	auto	sfml = new SfmlDisplay(800, 600);
	cr_assert(sfml->isOpen(), "Test window is open failed !\n");
	sfml->destroyWindow();
	sfml->Display();
	delete(sfml);
}

Test(Utils, FileExist, .description = "Check if file exist")
{
	cr_assert(checkFileExist("Makefile"), "Test for check existing file failed !");
	cr_assert_not(checkFileExist("dsqjlkdsq"), "Test for a file doesn't exist failed !");
}