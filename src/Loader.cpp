/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <dlfcn.h>
#include <iostream>
#include "../inc/Loader.hpp"
#include "../inc/ArcadeException.hpp"

Loader::Loader(const char *libraryPath)
{
	handle = dlopen(libraryPath, RTLD_LAZY);
	if (handle == nullptr) {
		throw arcade::LoaderError("Can't open Library !");
	}
	create = (IDisplay* (*)(unsigned int, unsigned int))dlsym(handle, "create_object");
	if (!create) {
		throw arcade::LoaderError("Can't find create_object symbol");
	}
	destroy = (void (*)(IDisplay*))dlsym(handle, "destroy_object");
	if (!destroy) {
		throw arcade::LoaderError("Can't find destroy_object symbol");
	}
}

Loader::~Loader()
{
	dlclose(handle);
}