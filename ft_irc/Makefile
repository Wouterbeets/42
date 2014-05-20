# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 16:27:25 by wbeets            #+#    #+#              #
#    Updated: 2014/05/20 14:47:43 by wbeets           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SER	= serveur
NAME_CLI	= client
FILES_SER	= main.c init_env.c clean_fd.c get_opt.c x.c main_loop.c \
	init_fd.c do_select.c check_fd.c \
	srv_create.c srv_accept.c \
	client_read.c client_write.c
FILES_CLI	= main.c ft_boo.c
SRC_SER		= $(addprefix serveur_src/, $(FILES_SER))
SRC_CLI		= $(addprefix client_src/, $(FILES_CLI))
OBJ_SER		= $(SRC_SER:serveur_src/%.c=.serveur_obj/%.o)
OBJ_CLI		= $(SRC_CLI:client_src/%.c=.client_obj/%.o)
FLAGS	= -Wall -Werror -Wextra
DFLAGS	= -Wall -Werror -Wextra -g3 -pedantic
LIBCOM	= -L libft -lft
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
INCLUDE	= -I includes -I libft/includes
DEB_SER		= .deb/serveur
DEB_CLI		= .deb/client	

all: disp lib disp2 $(NAME_CLI) $(NAME_SER) disp3

$(NAME_SER): $(OBJ_SER) $(OBJ_CLI)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING---EXECUTABLE---$(NAME_SER)---"
	@gcc $(OBJ_SER) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $(NAME_SER)
	@echo  "$(OK_COLOR)\t---SUCCES---$(NO_COLOR)"

$(NAME_CLI):  $(OBJ_CLI)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING---EXECUTABLE---$(NAME_CLI)---"
	@gcc $(OBJ_CLI) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $(NAME_CLI)
	@echo  "$(OK_COLOR)\t---SUCCES---$(NO_COLOR)"

disp:
	@echo  "$(WARN_COLOR)---PLEASE-HOLD---COMPILING--- $(NO_COLOR)"

disp2:
	@echo  "\t---CHECKING---OBJECTS---"

disp3:
	@echo  "$(WARN_COLOR)---COMPILATION COMPLETE---$(NO_COLOR)"

.client_obj/%.o: client_src/%.c
	@mkdir -p .client_obj/
	@echo ".\c"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

.serveur_obj/%.o: serveur_src/%.c
	@mkdir -p .serveur_obj/
	@echo ".\c"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .*_obj/
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME_SER) $(NAME_CLI)
	@rm -rf $(DEB)
	@make fclean -C libft/

gdb:
	@mkdir -p .deb/
	@cc -o $(DEB_SER) $(INCLUDE) $(DFLAGS) $(LIBCOM) $(SRC_SER)
	@cc -o $(DEB_CLI) $(INCLUDE) $(DFLAGS) $(LIBCOM) $(SRC_SER)

lib:
	@echo "\t---CHECKING LIBRARY---"
	@make -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

relib:
	@echo "\t---CHECKING LIBRARY---"
	@make re -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

re: fclean all

