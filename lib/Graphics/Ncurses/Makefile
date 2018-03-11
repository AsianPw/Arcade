##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Makefile for Ncurses shared Library
##

NAME	=	lncurses_graphic.so

CXX		=	g++

RM		=	rm -f

SRCS	=	./Ncurses.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -fPIC -shared
LDFLAGS		=	-lncurses

WARN_COLOR	=	\033[0;33m
COM_COLOR	=	\033[0;34m
OBJ_COLOR	=	\033[0;36m
OK_COLOR	=	\033[0;32m
NO_COLOR	=	\033[m
OK_STRING	=	"[OK]"
WARN_STRING	=	"[WARNING]"

all: $(NAME)

$(NAME): $(OBJS)
	@printf "%b" "\n$(WARN_COLOR)-----------------------Compilation Of $(NAME)----------------------$(NO_COLOR)\n";
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
ifneq ($(shell find -name '*.o'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Object file(s)\t\t$(OBJ_COLOR)($(OBJS))$(NO_COLOR)\n";
	@$(RM) $(OBJS)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING)\t$(COM_COLOR)No Object file to remove$(NO_COLOR)\n";
endif

fclean: clean
ifneq ($(shell find -name '$(NAME)'),)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\t\t$(COM_COLOR)Remove Project Binary\t\t$(OBJ_COLOR)($(NAME))$(NO_COLOR)\n";
	@$(RM) $(NAME)
else
	@printf "%b" "$(WARN_COLOR)$(WARN_STRING)\t$(COM_COLOR)No \"$(NAME)\" Binary found$(NO_COLOR)\n"
endif

re: fclean all

.PHONY: all clean fclean re