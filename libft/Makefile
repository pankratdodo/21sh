# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmartina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 15:32:30 by qmartina          #+#    #+#              #
#    Updated: 2019/05/03 16:27:34 by qmartina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_list_foreach.c ft_free_str.c ft_strndup.c ft_itoa_base.c ft_count.c ft_strcmp_start.c ft_sqrt.c ft_strjoin_cmp.c ft_strjoinch.c ft_realloc.c ft_swap.c ft_list_reverse.c ft_list_clear.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_printf.c ft_nbrlen.c ft_strjoinch_i.c get_next_line.c get_next_line_with_sym.c
OBJECT = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I ../inc

all: $(NAME)
	
$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OPTIONS) $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo "\033[32mlibft: Built library.\033[0m"

%.o:%.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJECT)
	@echo "\033[32mlibft: Cleaned up object files.\033[0m"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[32mlibft: Cleaned up compiled files.\033[0m"

re: fclean	all
