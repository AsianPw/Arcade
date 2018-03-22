//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <criterion/criterion.h>
#include <iostream>
#include "../inc/utils.hpp"
#include "../lib/Graphics/Sfml/Sfml.hpp"

Test(Utils, FileExist, .description = "Check if file exist")
{
	cr_expect(checkFileExist("Makefile"),
		"Test for check existing file failed !");
	cr_expect_not(checkFileExist("dsqjlkdsq"),
		"Test for a file doesn't exist failed !");
}