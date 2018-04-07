/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Time
*/
#include <chrono>
#include "Time.hpp"

long	getCurrentTime()
{
	return std::chrono::duration_cast<ms>(sc::now().time_since_epoch()).count();
}