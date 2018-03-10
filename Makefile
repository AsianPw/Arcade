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

SRCS		=	./src/main.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

UNIT_FLAGS	=	-lcriterion

LDFLAGS		=	-lsfml-window
CXXFLAGS	=	-W -Wall -Wextra
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

$(NAME): $(OBJS)
ifeq ($(DEBUG), y)
	@printf "%b" "$(WARN_COLOR)[Debug Mode]$(NO_COLOR)\n";
else
	@printf "%b" "$(OK_COLOR)[Release Mode]$(NO_COLOR)\n";
endif
	@printf "%b" "$(COM_COLOR)Compilation of ($(NAME)):$(NO_COLOR)\n";
	@$(CXX) $^ -o $@ $(LDFLAGS)

tests_run:
ifeq ($(DEBUG), y)
	@printf "%b" "$(WARN_COLOR)[Debug Mode]$(NO_COLOR)\n";
else
	@printf "%b" "$(OK_COLOR)[Release Mode]$(NO_COLOR)\n";
endif
	@printf "%b" "$(COM_COLOR)Compilation of ($(UNIT_TEST)):$(NO_COLOR)\n";
	@$(CXX) $(UNIT_SRCS) --coverage -o $(UNIT_TEST) $(UNIT_FLAGS) $(LDFLAGS)
	@printf "%b" "$(COM_COLOR)Launch of $(UNIT_TEST):$(NO_COLOR)\n";
	./$(UNIT_TEST)

clean:
	@printf "%b" "\n$(WARN_COLOR)---------Cleanup Directories---------$(NO_COLOR)\n\n"
ifneq ($(shell find -name '*~'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) $(COM_COLOR)Remove Temporary file(s)\t$(OBJ_COLOR)($(shell find -name '*~'))$(NO_COLOR)\n";
	@find -name '*~' -delete
endif
ifneq ($(shell find -name '*.gcda' -o -name '*.gcno'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) $(COM_COLOR)Remove Coverage file(s)\t$(OBJ_COLOR)($(shell find -name '*.gcda' -o -name '*.gcno'))$(NO_COLOR)\n";
	@find -name '*.gcda' -delete -o -name '*.gcno' -delete
endif
ifneq ($(shell find -name '*.o'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) $(COM_COLOR)Remove Object file(s)\t$(OBJ_COLOR)($(OBJS))$(NO_COLOR)\n";
	@$(RM) $(OBJS)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING) $(COM_COLOR)No Object file to remove$(NO_COLOR)\n";
endif

fclean: clean
	@printf "%b" "\n$(WARN_COLOR)-----------Remove Binaries-----------$(NO_COLOR)\n\n"
ifneq ($(shell find -name '$(UNIT_TEST)'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) $(COM_COLOR)Remove Unit Test Binary\t$(OBJ_COLOR)($(UNIT_TEST))$(NO_COLOR)\n";
	@$(RM) $(UNIT_TEST)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING) $(COM_COLOR)No Unit Test Binary found$(NO_COLOR)\n"
endif
ifneq ($(shell find -name '$(NAME)'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) $(COM_COLOR)Remove Project Binary\t$(OBJ_COLOR)($(NAME))$(NO_COLOR)\n";
	@$(RM) $(NAME)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING) $(COM_COLOR)No \"$(NAME)\" Binary found$(NO_COLOR)\n"
endif

re: fclean all

.PHONY: all clean fclean re tests_run
