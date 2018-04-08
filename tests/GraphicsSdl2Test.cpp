/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by asianpw,
*/

#include <criterion/criterion.h>
#include "../inc/Sdl2.hpp"
#include "../inc/ArcadeException.hpp"

using criterion::logging::warn;

Test(SDL2_TEST, ESCAPE_KEY)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));
	SDL_Event	event;

	event.key.keysym.scancode = SDL_SCANCODE_ESCAPE;
	sdl->setEvent(event);
	cr_assert(sdl->GetKey(arcade::KEYBOARD, arcade::ESCAPE),
		"ESCAPE_KEY test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, UNKNOWN_KEY)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));
	SDL_Event	event;

	event.key.keysym.scancode = SDL_SCANCODE_L;
	sdl->setEvent(event);
	cr_assert_not(sdl->GetKey(arcade::KEYBOARD, arcade::ESCAPE),
		"UNKNOWN_KEY test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, UNKNOWN_KEY2)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));

	SDL_Event	event;
	event.key.keysym.scancode = SDL_SCANCODE_ESCAPE;
	sdl->setEvent(event);
	cr_assert_not(sdl->GetKey(arcade::KEYBOARD, "L"),
		"UNKNOWN_KEY2 test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, EVENT)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));

	SDL_Event	event;
	event.window.event = SDL_WINDOWEVENT_CLOSE;
	sdl->setEvent(event);
	cr_assert(sdl->GetKey(arcade::WINDOW, arcade::CLOSE),
		"EVENT test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, WINDOW_IS_OPEN)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));

	cr_assert(sdl->isOpen(), "IS_OPEN test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, KEY_PRESSED)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));

	cr_assert(sdl->isKey(), "KEY_PRESSED test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, DISPLAY)
{
	std::unique_ptr<Sdl2>	sdl(new Sdl2(800, 600));

	cr_assert(sdl->Display(), "DISPLAY test Failed");
	sdl->destroyWindow();
}

Test(SDL2_TEST, FAILED_WINDOW_CREATION)
{
	warn << "An Exception must be catch for this test" << std::flush;
	try {
		new Sdl2(-1, -1);
	}
	catch (arcade::GraphicsLibraryError const& e) {
		warn << e.what() << std::flush;
		cr_assert(false, "Treokdmljsqld");
	}
	//cr_assert_fail("FAILED_WINDOW_CREATION failed");
}