# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 22:24:34 by gartanis          #+#    #+#              #
#    Updated: 2020/04/19 16:56:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
CC			:= gcc
CFLAGS		:= -c -Wall -Werror -Wextra
INC			:= includes/*.h
FILES		:= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
				ft_strncat.c ft_strlen.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memccpy.c ft_strdup.c \
				ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
				ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_iscntrl.c ft_isgraph.c ft_isblank.c \
				ft_islower.c ft_isupper.c get_next_line.c ft_strrev.c ft_dectostr.c ft_strchrpos.c ft_power.c \
				pft/ft_printf.c pft/parse_specifier.c pft/get_param.c pft/print_txt.c pft/print_hexadecimal.c pft/print_nbr.c pft/signed_nbr.c pft/unsigned_nbr.c \
				pft/print_octal.c pft/print_float.c pft/util_fl/convers_fl.c pft/util_fl/match_fl.c
OBJ		= $(addprefix obj/, $(notdir $(FILES:.c=.o)))

YELLOW 	:= \033[33;1m
GREEN 	:= \033[32;1m
WHITE	:= \033[39;1m
EOC		:= \033[00m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(WHITE)$(NAME)$(EOC) $(GREEN)  compiling completed$(EOC)"

$(OBJ): $(FILES)
	@$(CC) $(CFLAGS) -I $(INC) $^
	@mkdir -p obj && mv *.o obj/

clean:
	@rm -rf $(OBJ) obj includes/*.gch

fclean: clean
	@rm -f $(NAME)
	@echo "$(WHITE)$(NAME)$(EOC) $(YELLOW)  removed$(EOC)"

re: fclean all

.PHONY: clean fclean all re
