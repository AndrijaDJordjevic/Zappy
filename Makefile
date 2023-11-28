##
## EPITECH PROJECT, 2023
## zappy
## File description:
## global Makefile
##

AI	=	./ai/

SERVER	=	./server/

GUI	=	./gui/

RM	=	rm -rf

all:
	$(MAKE) -C $(AI)
	$(MAKE) -C $(SERVER)
	$(MAKE) -C $(GUI)

server:
	$(MAKE) -C $(SERVER)

server_tests_run:
	$(MAKE) -C $(SERVER) test_all

ai:
	$(MAKE) -C $(AI)

ai_tests_run:
	$(MAKE) -C $(AI) tests_run

gui:
	$(MAKE) -C $(GUI)

clean:
	$(MAKE) -C $(AI) clean
	$(MAKE) -C $(SERVER) clean
	$(MAKE) -C $(GUI) clean

fclean: clean
	$(MAKE) -C $(AI) fclean
	$(MAKE) -C $(SERVER) fclean
	$(MAKE) -C $(GUI) fclean

re: fclean all

test_all: server_tests_run ai_tests_run

.PHONY:	re fclean clean all server ai gui server_tests_run ai_tests_run
