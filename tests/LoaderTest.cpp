//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <criterion/criterion.h>
#include <iostream>
#include "../inc/Loader.hpp"
#include "../inc/ArcadeException.hpp"

Test(LOADER, INCOMPATIBLE_LIBRARY)
{
	cr_assert_throw(Loader((char *)"/usr/lib/man-db/libman.so"), arcade::LoaderError, "Incompatible library load !");
}

Test(LOADER, INCOMPATIBLE_EXTENTION)
{
	cr_assert_throw(Loader((char *)"/usr/lib/man-db/libman.s"), arcade::LoaderError, ".so Load !");
}

Test(EXCEPTION, MESSAGE)
{
	try {
		Loader((char *)"/usr/lib/man-db/libman.s");
	}
	catch (arcade::LoaderError &e) {
		cr_assert(!strcmp(e.what(), "Can't open Library !"), "Test failed");
	}
}