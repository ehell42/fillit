# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 22:26:44 by aguiller          #+#    #+#              #
#    Updated: 2019/12/23 13:31:53 by aguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c get_next_line.c first_check.c second_check.c tetra_func.c\
third_check.c solver.c find_min_square.c koord_func.c functions.c

NAME = fillit

SRC_LIB = libft/ft_atoi.c \
		libft/ft_bzero.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_itoa.c\
		libft/ft_lstadd.c\
		libft/ft_lstdel.c\
		libft/ft_lstdelone.c\
		libft/ft_lstiter.c\
		libft/ft_lstmap.c\
		libft/ft_lstnew.c\
		libft/ft_memalloc.c\
		libft/ft_memccpy.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memdel.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_putchar.c\
		libft/ft_putchar_fd.c\
		libft/ft_putendl.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putstr.c\
		libft/ft_putstr_fd.c\
		libft/ft_strcat.c	\
		libft/ft_strchr.c\
		libft/ft_strclr.c\
		libft/ft_strcmp.c\
		libft/ft_strcpy.c\
		libft/ft_strdel.c\
		libft/ft_strdup.c\
		libft/ft_strequ.c\
		libft/ft_striter.c\
		libft/ft_striteri.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlen.c\
		libft/ft_strmap.c\
		libft/ft_strmapi.c\
		libft/ft_strncat.c\
		libft/ft_strncmp.c\
		libft/ft_strncpy.c\
		libft/ft_strnequ.c\
		libft/ft_strnew.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_strsplit.c\
		libft/ft_strstr.c\
		libft/ft_strsub.c\
		libft/ft_strtrim.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c


OBJ = $(SRC:%.c=%.o)

all: $(NAME) 

NAME_LIB = libft.a

OBJ_LIB = $(SRC_LIB:%.c=%.o)

$(NAME_LIB): $(OBJ_LIB)
	@ar rcs $(NAME_LIB) $(OBJ_LIB)

cleanlib:
	@/bin/rm -f $(OBJ_LIB)

fcleanlib: cleanlib
	@/bin/rm -f $(NAME_LIB)

relib: fcleanlib $(NAME_LIB)

$(NAME): $(NAME_LIB) $(OBJ) 
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) libft.a

%.o:%.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean: cleanlib
	@/bin/rm -f $(OBJ)

fclean: clean fcleanlib
	@/bin/rm -f $(NAME)

re: fclean relib all 

