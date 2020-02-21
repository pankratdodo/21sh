# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmartina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 16:01:11 by qmartina          #+#    #+#              #
#    Updated: 2019/10/17 16:01:15 by qmartina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	21sh

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)libft.h

LIBS		=	-ltermcap

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	objs/

SRC_BASE = builtins/ft_cd.c\
        builtins/ft_cd_2.c\
        builtins/ft_cd_3.c\
        builtins/ft_echo.c\
        builtins/ft_echo2.c\
        builtins/allenv/ft_env.c\
 	builtins/allenv/global_env.c\
        errors/errror_handler.c\
        exec/ft_create_file.c\
        exec/ft_do_pipe.c\
        exec/ft_fun_fork.c\
	lexer/lexer.c\
	lexer/change_dol.c\
	lexer/change_spaces.c\
	lexer/cr_and_add_tokens.c\
	lexer/dop_funs.c\
	lexer/all_bax_and_hist_change.c\
	lexer/kill_dop_structure.c\
	lexer/word_sizes.c\
	lexer/change_hist_exp.c\
	lexer/change_str_by_str.c\
	lexer/get_opt_type.c\
	lexer/history_search.c\
	nucleus/ft_read_8.c\
	nucleus/ft_c.c\
	nucleus/input_mode.c\
	g_builtins.c\
	nucleus/do_add.c\
	nucleus/ft_realloc_buff.c\
	nucleus/ft_cleanstr.c\
	nucleus/ft_setcursor.c\
	nucleus/ft_add_sumchar.c\
	nucleus/ft_put_n.c\
	nucleus/ft_do_leftright.c\
	nucleus/ft_upcursor.c\
	nucleus/ft_downcursor.c\
	nucleus/ft_back_slovo.c\
	nucleus/ft_next_slovo.c\
	nucleus/ft_arrows.c\
	nucleus/ft_putcut.c\
	nucleus/ft_cut.c\
	nucleus/dop_tab_funs.c\
	nucleus/ft_do_delch.c\
	nucleus/ft_cut_copy.c\
	nucleus/ft_do_copy.c\
	nucleus/ft_strsplit1.c\
	nucleus/ft_print_tab.c\
	nucleus/ft_realloc_tab.c\
	nucleus/show_history.c\
	nucleus/ft_head_memory.c\
	nucleus/ft_memory.c\
	nucleus/ft_dop_history.c\
	nucleus/ft_putmemory.c\
	nucleus/ft_start_read.c\
	nucleus/ft_printf_helper.c\
	nucleus/ft_cheak_quote.c\
	nucleus/ft_add_intput_que.c\
	nucleus/find_history.c\
	nucleus/ft_arrnew.c\
	nucleus/ft_arrdel.c\
	nucleus/del_readline.c\
	nucleus/tab.c\
	parser/dop_parser.c\
	parser/change_tilda.c\
	parser/main_parser.c\
	hash/hash_table.c\
	hash/hash_table_2.c\
	hash/hash_error.c\
	ft_distruct.c\
	ft_error_q.c\
	ft_signal.c\
	ft_take_arg.c\
	check_file.c\
	main.c\
	shell_lvl.c\
	builtins/allenv/main_env.c\

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) \
		$(LIBFT_LIB) \
		$(FLAGS)
	@strip -x $@
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K\n"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K\n"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K\n"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
