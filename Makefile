##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for Arcade
##

DEBUG		=	no

NAME		=	arcade

UNIT_TEST	=	unit_test

CXX		=	g++

RM		=	rm -f

UNIT_SRCS	=	./tests/display.cpp	\
				./tests/GraphicsSfmlTest.cpp	\
				./tests/GraphicsSdl2Test.cpp	\
				./tests/LoaderTest.cpp	\
				./src/utils.cpp	\
				./lib/Graphics/Sfml/Sfml.cpp	\
				./lib/Graphics/Sdl2/Sdl2.cpp	\
				./src/Loader.cpp	\
				./src/ArcadeException.cpp	\

SRCS		=	./src/main.cpp	\
				./src/utils.cpp	\
				./src/Loader.cpp	\
				./src/ArcadeException.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

UNIT_FLAGS	=	-lcriterion -lsfml-graphics -lsfml-window -lsfml-system -lSDL2

LDFLAGS		=	-ldl
CXXFLAGS	=	-W -Wall -Wextra -std=c++14
CPPFLAGS	=	-I ./inc/

ifeq ($(DEBUG), y)
CXXFLAGS	+=	-g3
endif

WARN_COLOR	=	\033[0;33m
COM_COLOR	=	\033[0;34m
OBJ_COLOR	=	\033[0;36m
OK_COLOR	=	\033[0;32m
NO_COLOR	=	\033[m
OK_STRING	=	"[OK]"
WARN_STRING	=	"[WARNING]"

all: $(NAME)

install:
	sudo apt update
	sudo apt install libsdl2-dev
	sudo apt install libsfml-dev
	sudo apt install libglfw3
	sudo apt install libglfw3-dev

$(NAME): $(OBJS)
ifeq ($(DEBUG), y)
	@printf "%b" "\n$(WARN_COLOR)-----------------------[Debug Mode] $(NAME)----------------------$(NO_COLOR)\n";
else
	@printf "%b" "\n$(OK_COLOR)----------------------[Release Mode] $(NAME)---------------------$(NO_COLOR)\n";
endif
	@make --no-print-directory -C ./lib/Graphics all
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)

generate_coverage: tests_run
	@lcov --directory . -c -o rapport.info
	@genhtml -o ../rapport -t "Coverage of tests" rapport.info

tests_run: all
	@printf "%b" "\n$(COM_COLOR)--------------------Compilation Of $(UNIT_TEST)--------------------$(NO_COLOR)\n";
	$(CXX) $(CXXFLAGS) $(UNIT_SRCS) --coverage -o $(UNIT_TEST) $(UNIT_FLAGS) $(LDFLAGS)
	@printf "%b" "\n$(COM_COLOR)------------------------Launch Unit Test------------------------$(NO_COLOR)\n";
	./$(UNIT_TEST) -j1 --always-succeed

clean:
	@printf "%b" "\n$(WARN_COLOR)------------------Cleanup Graphics Library Dir-----------------$(NO_COLOR)\n\n"
	@make --no-print-directory -C ./lib/Graphics clean
	@printf "%b" "\n$(WARN_COLOR)----------------------Cleanup Directories----------------------$(NO_COLOR)\n\n"
ifneq ($(shell find -name '*~'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Temporary file(s)\t$(OBJ_COLOR)($(shell find -name '*~'))$(NO_COLOR)\n";
	@find -name '*~' -delete
endif
ifneq ($(shell find -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Coverage file(s)\t\t$(OBJ_COLOR)($(shell find -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov'))$(NO_COLOR)\n";
	@find -name '*.gcda' -delete -o -name '*.gcno' -delete -o -name '*.gcov' -delete
endif
ifneq ($(shell find -name '*.info'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Info file(s)\t\t$(OBJ_COLOR)($(shell find -name '*.info'))$(NO_COLOR)\n";
	@find -name '*.info' -delete
endif
ifneq ($(shell find -name '*.o'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Object file(s)\t\t$(OBJ_COLOR)($(OBJS))$(NO_COLOR)\n";
	@$(RM) $(OBJS)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING)\t$(COM_COLOR)No Object file to remove$(NO_COLOR)\n";
endif

fclean: clean
	@printf "%b" "\n$(WARN_COLOR)--------------------Cleanup Graphics Library-------------------$(NO_COLOR)\n\n"
	@make --no-print-directory -C ./lib/Graphics fclean
	@printf "%b" "\n$(WARN_COLOR)------------------------Remove Binaries------------------------$(NO_COLOR)\n\n"
ifneq ($(shell find -name '$(UNIT_TEST)'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Unit Test Binary\t\t$(OBJ_COLOR)($(UNIT_TEST))$(NO_COLOR)\n";
	@$(RM) $(UNIT_TEST)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING)\t$(COM_COLOR)No Unit Test Binary found$(NO_COLOR)\n"
endif
ifneq ($(shell find -name '$(NAME)'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Project Binary\t\t$(OBJ_COLOR)($(NAME))$(NO_COLOR)\n";
	@$(RM) $(NAME)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING)\t$(COM_COLOR)No \"$(NAME)\" Binary found$(NO_COLOR)\n"
endif
	@printf "%b" "\n$(OK_COLOR)--------------------------All clear !--------------------------$(NO_COLOR)\n\n"

re: fclean all

.PHONY: all clean fclean re tests_run generate_coverage install
