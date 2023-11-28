##
## EPITECH PROJECT, 2023
## zappy
## File description:
## ai Makefile
##

SRC	=	./src/

NAME	=	zappy_ai

$(NAME):
			cp $(SRC)main.py ./
			mv main.py $(NAME)
			chmod +x $(NAME)
			mv $(NAME) ../

all:	$(NAME)

fclean:
		rm -rf ../$(NAME)

tests_run:
	python3 src/unit_tests.py -v
re:	fclean all

.PHONY: all clean fclean re
