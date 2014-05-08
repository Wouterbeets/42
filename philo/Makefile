# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/25 20:36:16 by gpetrov           #+#    #+#              #
#    Updated: 2014/04/25 20:56:44 by gpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
FILES		=\
			main.c\
			init_ph.c\
			philo.c 

SRCS		= $(addprefix srcs/, $(FILES))
OBJS		= $(SRCS:ft_otool_dir/srcs/%.c=ft_otool_dir/.obj/%.o)
INC			= -I includes -I libft/includes
FLAGS		=  -Wall -Wextra -Werror
LIB			= -L libft -lft

all: $(NAME)

$(NAME): $(OBJS) 
	@make -C libft
	@cc $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(LIB)
	@echo "\n > \033[36philo\033[m project compilation [\033[32mDONE\033[m]\n"

.obj/%.o: srcs/%.c
	@mkdir -p .obj
	@cc -c $< -o $@ $(FLAGS) $(INC)

clean:
	@rm -rf .obj

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "fclean : [\033[32mDONE\033[m]"

gdb:
	@cc $(FLAGS) $(SRCS) -g -o deb $(INC) $(LIB)

re: fclean all
