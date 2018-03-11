##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Makefile for Compile all graphics library
##

all:
	@for file in ./**/ ; do \
		[ -f $$file/Makefile ] && make --no-print-directory -C "$$file" all ; \
	done

clean:
	@for file in ./**/ ; do \
		[ -f $$file/Makefile ] && make --no-print-directory -C "$$file" clean ; \
	done

fclean: clean
	@for file in ./**/ ; do \
		[ -f $$file/Makefile ] && make --no-print-directory -C "$$file" fclean ; \
	done

re: fclean all

.PHONY: all re fclean clean