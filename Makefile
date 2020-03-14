# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 18:06:29 by gartanis          #+#    #+#              #
#    Updated: 2020/03/14 19:00:11 by gartanis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGETA	:= push_swap
TARGETB := checker
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc
LIBFT	:= libft/ft_atoi.c libft/ft_isdigit.c libft/ft_strcmp.c libft/ft_strlen.c libft/ft_strsplit.c
SRC 	:= srcs/*.c
OBJ 	:= $(notdir $(SRCF:.c=.o) $(LIBFT:.c=.o))
OBJF 	:= *.o
INC		:= -I includes/push_swap.h libft/libft.h

# VPATH := includes srcs
# VAR := $(NAME) checker
# VAR := $(addprefix xyu_, $(VAR))
# VAR := $(addsuffix _pizda, $(VAR))
# SEARCH_WILDCARDS := includes/*.h srcs/*.c
# SRC_FILES := $(wildcard $(SEARCH_WILDCARDS))
# SRC_FILES := $(notdir $(SRC_FILES))
# OBJ_FILES := $(SRC_FILES:.c=.o)

# SRCH := srcs/*.c includes/*.h
# SRCS := $(wildcard $(SRCH))
# SRCS := $(notdir $(SRCS))

all: $(TARGETA)

$(TARGETA): $(OBJF)
	@$(CC) $^ -o $@
	@mkdir obj && mv *.o obj/
	@echo "Compiling $(TARGETA): \033[32mSUCCESS\033[00m"

$(OBJF): $(SRC) $(LIBFT)
	@printf "[.:]\r"
	@$(CC) -c $(INC) $^
	@printf "[:.]\r"

clean:
	@rm -rf *.o obj
	@echo "$(TARGETA): removed object files \033[32mOK\033[00m"

fclean: clean
	@rm $(TARGETA)
	@echo "$(TARGETA): removed \033[32mOK\033[00m"

re: fclean all