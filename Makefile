# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 18:06:29 by gartanis          #+#    #+#              #
#    Updated: 2020/03/15 17:39:20 by gartanis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGETA	:= push_swap
TARGETB := checker
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc
LIBF	:= libft/ft_atoi.c libft/ft_isdigit.c libft/ft_strcmp.c libft/ft_strlen.c libft/ft_strsplit.c
SRCF 	:= srcs/check_stack.c srcs/init_stack.c srcs/push_swap.c
OBJF 	:= $(addprefix obj/, $(notdir $(SRCF:.c=.o) $(LIBF:.c=.o)))
INC		:= includes/push_swap.h
OBJDIR	:= obj

# VPATH := includes srcs
# VAR := $(NAME) checker
# VAR := $(addprefix xyu_, $(VAR))
# VAR := $(addsuffix _pizda, $(VAR))


all: $(TARGETA)

$(TARGETA): $(OBJF)
	@$(CC) $^ -o $@
	@echo "[$(TARGETA)] \033[32mcompiling completed\033[00m"

$(OBJF): $(SRCF) $(LIBF) $(INC)
	@printf " Compiling [.:]\r"
	@$(CC) -c -I $(INC) $^
	@mkdir -p obj && mv *.o obj/
	@printf " Compiling [:.]\r"

clean:
	@rm -rf *.o obj
	@echo "[$(TARGETA)] \033[33mremoved object files\033[00m"

fclean: clean
	@rm $(TARGETA)
	@echo "[$(TARGETA)] \033[33mremoved program\033[00m"

re: fclean all

.PHONY: clean fclean re all