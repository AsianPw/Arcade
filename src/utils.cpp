//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstddef>
#include <cstdint>
#include <vector>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

bool	checkFileExist(std::string const & file) noexcept
{
	if (!access(file.c_str(), F_OK))
		return true;
	return false;
}

std::vector<uint8_t>	*createFramebuffer(size_t width, size_t height, size_t type)
{
	std::vector<uint8_t>	*framebuffer = nullptr;
	size_t	count = 0;

	try {
		framebuffer = new std::vector<uint8_t>(width * height * type);
	}
	catch (std::bad_alloc&) {
		throw;
	}

	while (count < height * width * type) {
		framebuffer->push_back(0);
		count += 1;
	}
	return framebuffer;
}