//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <cstddef>
#include <cstdint>
#include <vector>

std::vector<uint8_t>	*createFramebuffer(size_t width, size_t height, size_t type)
{
	auto	*framebuffer = new std::vector<uint8_t>;
	size_t	count = 0;

	while (count < height * width * type)
	{
		framebuffer->push_back(0);
		count += 1;
	}
	return (framebuffer);
}