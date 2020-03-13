# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 18:06:29 by gartanis          #+#    #+#              #
#    Updated: 2020/03/13 21:22:09 by gartanis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGETA	:= push_swap
TARGETB := checker
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc
LIBFT	:= libft/ft_atoi.c libft/ft_isdigit.c libft/ft_strcmp.c libft/ft_strlen.c libft/ft_strsplit.c
SRC 	:= srcs/*.c
OBJ 	:= $(notdir $(SRCF:.c=.o) $(LIBFT:.c=.o))
# OBJF 	:= *.o

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

$(TARGETA): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): $(SRC) $(LIBFT)
	$(CC) -c $^

clean:
	rm -rf *.o
fclean: clean
	rm $(TARGETA)


# %.o: %.c
# 	gcc -c $