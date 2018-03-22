/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include "../inc/ArcadeException.hpp"

arcade::Error::Error(std::string const &e) noexcept : message(e)
{
}

const char	*arcade::Error::what() const noexcept
{
	return message.what();
}

arcade::LoaderError::LoaderError(std::string const &e) noexcept : Error(e)
{
}

arcade::GraphicsLibraryError::GraphicsLibraryError(std::string const &e) noexcept : Error(e)
{
}
