# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 18:06:29 by gartanis          #+#    #+#              #
#    Updated: 2020/04/27 16:23:14 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGETA	:= push_swap
TARGETB := checker
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc
LIBF	:= libft/$(SRC_CH:.c=.o)
SRCF 	:= srcs/check_stack.c srcs/init_stack.c srcs/sort.c srcs/operations.c srcs/operations2.c srcs/get_arg.c srcs/utility.c
SRC_PW	:= srcs/push_swap.c
SRC_CH	:= srcs/checker.c
OBJF 	:= $(addprefix obj/, $(notdir $(SRCF:.c=.o) $(LIBF:.c=.o)))
OBJ_PW	:= $(addprefix obj/, $(notdir $(SRC_PW:.c=.o)))
OBJ_CH	:= $(addprefix obj/, $(notdir $(SRC_CH:.c=.o)))
INC		:= includes/push_swap.h
OBJDIR	:= obj

YELLOW 	:= \033[33;1m
GREEN 	:= \033[32;1m
WHITE	:= \033[39;1m
EOC		:= \033[00m

all: $(TARGETA) $(TARGETB)

$(TARGETA): $(OBJF) $(OBJ_PW)
	@$(CC) $^ -o $@ libft/libft.a
	@echo "$(WHITE)$(TARGETA)$(EOC) $(GREEN)compiling completed$(EOC)"

$(TARGETB): $(OBJF) $(OBJ_CH)
	@$(CC) $^ -o $@ libft/libft.a
	@echo "$(WHITE)$(TARGETB)$(EOC) $(GREEN)  compiling completed$(EOC)"

$(OBJF) $(OBJ_PW) $(OBJ_CH): $(SRCF) $(SRC_PW) $(SRC_CH) $(INC)
	@printf " Compiling [.:]\r"
	@cd libft/ && make
	@$(CC) -c -I $(INC) $^
	@mkdir -p obj && mv *.o obj/
	@printf " Compiling [:.]\r"

clean:
	@rm -rf *.o obj includes/push_swap.h.gch
	@cd libft/ && make clean
	@echo "$(WHITE)obj files$(EOC) $(YELLOW)removed$(EOC)"

fclean: clean
	@rm -f $(TARGETA) $(TARGETB) OPERATIONS.txt
	@cd libft/ && make fclean
	@echo "$(WHITE)$(TARGETA)$(EOC) $(YELLOW)removed$(EOC)"
	@echo "$(WHITE)$(TARGETB)$(EOC) $(YELLOW)  removed$(EOC)"

re: fclean all

.PHONY: clean fclean re all