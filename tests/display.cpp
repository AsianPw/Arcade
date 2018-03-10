//
// EPITECH PROJECT, 2021
// cpp_arcade
// File description:
// Created by asianpw,
//

#include <criterion/criterion.h>
#include <iostream>
#include "../inc/utils.hpp"

ReportHook(PRE_SUITE)(struct criterion_suite_set *suite_set) {
	std::cout << suite_set->suite.name << " suite:" << std::endl;
}

ReportHook(PRE_TEST)(struct criterion_test *test) {
	std::cout << "Begin of " << test->name << ":\t" << test->data->description << std::endl;
}

ReportHook(POST_TEST)(struct criterion_test_stats *stats) {
	std::cout << "\tTest elapsed:" << stats->elapsed_time << std::endl;
}

ReportHook(POST_SUITE)(struct criterion_suite_stats *stats) {
	std::cout << stats->suite->name << " is Finish" << std::endl;
}

Test(Generate, framebuffer, .description = "Check if framebuffer is correctly allocate")
{
	std::vector<uint8_t>	*tmp = createFramebuffer(800, 600, 4);
	cr_assert(tmp->size() == (800 * 600 * 4), "Test if size of framebuffer is good\n");
}
