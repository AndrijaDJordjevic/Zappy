##
## EPITECH PROJECT, 2023
## zappy
## File description:
## gui Makefile
##

CC	=	g++

DIR_INC = ./Headers/ -I./Headers/Object/ -I./Headers/Network/

INCLUDE    =    -I$(DIR_INC) -I./Headers/Scenes/

CPPFLAGS    =    -Wall -Wextra $(INCLUDE)

CFLAGS    =    -lraylib -lm

NAME    =    zappy_gui

SRC    =    main.cpp						\
			Core.cpp						\
			Broadcaster.cpp					\
			Object/Map.cpp					\
			Object/Player.cpp				\
			Object/Team.cpp					\
			Object/Tile.cpp					\
			Object/Button.cpp				\
			Object/Texture2D.cpp			\
			Object/Inventory.cpp			\
			Object/DataManager.cpp			\
			Object/ResourceManager.cpp		\
			Network/Parser.cpp				\
        	Network/Network.cpp				\
			Scenes/Menu.cpp					\
			Scenes/Game.cpp					\

DIR_SRC    =    ./Source/

PATH_SRC =	$(addprefix $(DIR_SRC), $(SRC))

OBJ	=	$(PATH_SRC:.cpp=.o)

RM	=	rm -rf

.PHONY:	re fclean clean all

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -g3 -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)
	mv $(NAME) ../


clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UTILS)

fclean:	clean
	$(RM) ../$(NAME)

re: fclean all
