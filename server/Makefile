##
## EPITECH PROJECT, 2023
## zappy
## File description:
## server Makefile
##

CC	=	gcc

OBJ	=	$(PATH_SRC:.c=.o)

OBJ_CLIENT_CMD	=	$(PATH_CLIENT_CMD:.c=.o)

OBJ_MAIN	=	$(MAIN_PATH:.c=.o)

NAME	=	zappy_server

RM	=	rm -rf

TEST_NAME	=	unit_tests

DIR_INC = ./include/

DIR_CLIENT_CMD = commands_handling/

DIR_SRC	=	./src/

DIR_TEST = tests/

PATH_CLIENT_CMD	=	$(addprefix $(DIR_SRC), $(addprefix $(DIR_CLIENT_CMD), \
$(SRC_CLIENT_CMD)))

PATH_SRC	=	$(addprefix $(DIR_SRC), $(SRC))

MAIN_PATH	=	$(addprefix $(DIR_SRC), $(MAIN))

TEST_PATH	= $(addprefix $(DIR_TEST), $(TEST_FILES))

MAIN	=		main.c									\

SRC	=	utils/display_help.c							\
		utils/str_to_word_array.c						\
		utils/error_handling.c							\
		utils/arguments_handling.c						\
		utils/tools.c									\
		utils/my_strlen_2d.c 							\
		utils/send_to_gui.c 							\
		utils/countdown.c 								\
		utils/send_message.c 							\
		server_handling/cmd_queue/check_cmd_queue.c 	\
		server_handling/cmd_queue/free_cmd_queue.c 		\
		server_handling/cmd_queue/handle_cmd_queue.c 	\
		server_handling/handle_players_life.c 			\
		server_handling/get_available_cmd.c 			\
		server_handling/handle_server.c 				\
		server_handling/init_zappy.c					\
		server_handling/handle_fd_sets.c				\
		server_handling/run_server.c					\
		server_handling/handle_new_connection.c 		\
		server_handling/handle_client_data.c			\
		server_handling/handle_client_commands.c 		\
		server_handling/singleton.c						\
		server_handling/auth/auth_client.c				\
		server_handling/auth/auth_egg.c					\
		server_handling/get_nbr_team.c					\
		server_handling/message_server.c				\
		map_handling/initiate_map.c 						\
		map_handling/ressource_to_str.c					\
		map_handling/create_map.c							\
		map_handling/free_map.c							\
		map_handling/ressources_management.c				\
		map_handling/print_map.c							\
		eggs_handling/manage_eggs.c						\
		eggs_handling/init_eggs.c						\
		eggs_handling/print_eggs.c 						\
		eggs_handling/delete_eggs.c 					\
		clients_handling/new_client.c 					\
		clients_handling/init_clients.c 				\
		clients_handling/get_clients.c 					\
		clients_handling/kill_clients.c 				\
		clients_handling/random_spawn_player.c 			\


SRC_CLIENT_CMD	=	client/forward.c										\
					client/right.c											\
					client/left.c											\
					client/look.c											\
					client/look_utils.c 									\
					client/inventory.c										\
					client/broadcast.c										\
					client/connect_nbr.c									\
					client/fork.c											\
					client/eject.c											\
					client/take.c											\
					client/set.c											\
					client/take_set_utils.c									\
					client/direction/get_cardinal_points_directions.c 		\
					client/direction/get_directions.c 						\
					client/direction/find_best_direction.c 					\
					gui/map_size.c											\
					gui/tile_content.c										\
					gui/map_content.c										\
					gui/pnw.c												\
					gui/player_info.c										\
					gui/teams_name.c										\
					gui/time_unit.c											\
					gui/broadcast.c											\
					gui/ressources_handling.c								\
					gui/death.c 											\
					gui/start_incantation.c 								\
					gui/end_incantation.c	 								\
					incantation/incantation.c								\
					incantation/incantation_utils.c							\
					incantation/incantation_get.c							\
					incantation/incantation_lvl_2.c							\
					incantation/incantation_easy.c							\
					incantation/incantation_medium.c						\
					incantation/incantation_hard.c							\
					incantation/incantation_check.c							\

TEST_FILES	=	tests_error_handling.c			\
				tests_arguments_handling.c		\
				tests_is_params_valid.c			\
				tests_server.c					\
				tests_singelton.c				\
				tests_str_to_word_array.c		\
				tests_handle_new_connection.c	\

TEST_FONC	=	tests/fonctional_tests/fonctional_tests.py		\

CPPFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)

LDFLAGS		=	-lm

INCLUDE	=	-I$(DIR_INC)

UNITFLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ_CLIENT_CMD) $(OBJ_MAIN) $(OBJ)
	$(CC) -g3 -o $(NAME) $(OBJ_MAIN) $(OBJ) $(OBJ_CLIENT_CMD) $(CPPFLAGS) \
	$(LDFLAGS)
	mv $(NAME) ../

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_CLIENT_CMD)
	$(RM) $(OBJ_UTILS)
	$(RM) $(OBJ_MAIN)
	$(RM) unit_tests*
	$(RM) *.gcda
	$(RM) *.gcno

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean all

tests_run:
	$(CC) -o $(TEST_NAME) $(PATH_SRC) $(PATH_CLIENT_CMD) $(TEST_PATH) \
	$(UNITFLAGS) $(CPPFLAGS) $(LDFLAGS)
	./$(TEST_NAME) && gcovr tests/

fonctional_test: re
	./$(TEST_FONC)

test_all: fonctional_test tests_run

.PHONY:	re fclean clean all tests_run fonctional_test
