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

Test(Generate, framebuffer, .description = "Check if framebuffer is correctly allocate")
{
	std::vector<uint8_t>	*tmp = createFramebuffer(800, 600, 4);

	cr_assert(tmp->size() == (800 * 600 * 4), "Test if size of framebuffer is good\n");
}

Test(Generate, framebuffer_bad_alloc, .description = "Test of big framebuffer allocation")
{
	cr_assert_any_throw(createFramebuffer(((size_t)~0), 100000, 4), "Exception doesn't catch\n");
}



Test(Utils, FileExist, .description = "Check if file exist")
{
	cr_assert(checkFileExist("Makefile"), "Test for check existing file failed !");
	cr_assert_not(checkFileExist("dsqjlkdsq"), "Test for a file doesn't exist failed !");
}