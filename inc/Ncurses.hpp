/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_NCURSES_HPP
#define CPP_ARCADE_NCURSES_HPP

#include <string>
#include <map>
#include <ncurses.h>
#include "IDisplay.hpp"

class NcursesDisplay : public IDisplay {
public:
	NcursesDisplay(size_t, size_t);
	~NcursesDisplay() override;
public:
	bool Display() override;
	bool isOpen() override;
	bool GetKey(arcade::TypeEvent typeEvent, std::string const &type) override;
	bool isKey() override;
	bool	loadTexture(std::map<std::string, Texture> const&) override;
	bool	loadText(std::map<std::string, Texture> const&) override;
	void changeLibrary(std::string const &path) override;
	bool getChange() const override;
	void setChange(bool b) override;
	const std::string &getLibraryPath() const override;
	void destroyWindow() override;
	const std::string &getNewGamePath() const override;
	void setNewGamePath(std::string const &string) override;

	bool loadMap(std::vector<std::vector<char>> const &vector) override;

	bool getSwitchScene() const override;
	void setSwitchScene(bool b) override;
private:
	std::map<std::string, int> allEvent;
	int currentKey;
	WINDOW *window;
};

#endif //CPP_ARCADE_NCURSES_HPP
