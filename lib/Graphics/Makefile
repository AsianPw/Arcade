##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Makefile for Compile all graphics library
##

NO_COLOR	=	\033[m
COM_COLOR	=	\033[0;34m

all:
	@printf "%b" "\n$(COM_COLOR)---------------------Compilation Of Graphics--------------------$(NO_COLOR)\n";
	@for file in ./**/ ; do \
		[ -f $$file/Makefile ] && make --no-print-directory -C "$$file" all ; \
	done
	@printf "%b" "\n$(COM_COLOR)---------------------------------Done---------------------------$(NO_COLOR)\n";

clean:
	@for file in ./**/ ; do \
		[ -f $$file/Makefile ] && make --no-print-directory -C "$$file" clean ; \
	done

fclean:
	@for file in ./**/ ; do \
		[ -f $$file/Makefile ] && make --no-print-directory -C "$$file" fclean ; \
	done


re: fclean all

.PHONY: all re fclean clean