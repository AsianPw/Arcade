/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#ifndef CPP_ARCADE_ARCADEEXCEPTION_HPP
#define CPP_ARCADE_ARCADEEXCEPTION_HPP

#include <string>
#include <stdexcept>

namespace arcade {
	class Error : public std::exception {
	public:
		explicit Error(std::string const &e) noexcept;
		const char *what() const noexcept override;
	protected:
		std::runtime_error message;
	};

	class LoaderError : public Error {
	public:
		explicit LoaderError(std::string const &e) noexcept;
	};

	class GraphicsLibraryError : public Error {
	public:
		explicit GraphicsLibraryError(std::string const &e) noexcept;
	};
}

#endif //CPP_ARCADE_ARCADEEXCEPTION_HPP
