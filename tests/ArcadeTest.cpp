/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** ArcadeTest
*/

#include <criterion/criterion.h>
#include "../inc/Arcade.hpp"
#include "../inc/ArcadeException.hpp"

Test(START_ARCADE, TEST_EXCEPTION)
{
	char	path[] = "just_a_library_path";

	cr_assert_throw(startArcade(path), arcade::CoreError, "StartArcade Exception not catch");
}