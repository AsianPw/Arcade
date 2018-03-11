/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <dlfcn.h>
#include <iostream>
#include "../inc/Loader.hpp"

Loader::Loader(char *libraryPath)
{
	handle = dlopen(libraryPath, RTLD_LAZY);

	if (handle == nullptr) {
		std::cerr << "Fail to load the library" << std::endl;
		exit(84);
	}
	create = (IDisplay* (*)(unsigned int, unsigned int))dlsym(handle, "create_object");
	if (create == nullptr) {
		std::cerr << "Fail to load create" << std::endl;
		exit(84);
	}
	destroy = (void (*)(IDisplay*))dlsym(handle, "destroy_object");
}

Loader::~Loader()
{
	dlclose(handle);
}