# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/09/18 03:49:45 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra
#-fsanitize=address

NAME		=	parsing_test

LIB_PATH	=	libft
LIB			=	libft.a

LIBS		=	$(LIB_PATH)/$(LIB) \

P_SRC_DIR	=	parser
P_SOURCES	=	parser.c \
				ft_make_args.c \
				meta_priority.c \
				parse_struct_tools.c \

LEX_SRC_DIR	=	lexer
LEX_SOURCES	=	lexer.c \
				ft_is_token.c \
				token_tools.c \

LIN_SRC_DIR	=	line_editing
LIN_SOURCES	=	clipboard_tools.c \
				ctrl_keys.c \
				cursor_moves.c \
				cursor_tools.c \
				fast_cursor_moves.c \
				ft_enter.c \
				ft_get_line_form.c \
				ft_get_next_cmd_line.c \
				get_term_size.c \
				history.c \
				line_edit.c \
				line_edit_cut.c \
				prompt.c \
				reprint_line.c \
				termcaps.c \

ERR_SRC_DIR	=	error_exit
ERR_SOURCES	=	error_exit.c \
				perror1.c \
				perror2.c \

VAR_SRC_DIR	=	var_expansion
VAR_SOURCES	=	dollar_expansion.c \
				expansion_tools.c \
				star_expansion.c \
				tilde_expansion.c \
				var_expanding.c \

BI_SRC_DIR	=	built_in
BI_SOURCES	=	ft_built_in.c \
				ft_built_in_cd.c \
				ft_built_in_env.c \
				ft_built_in_env2.c \
#				ft_hash.c \

SRC_DIR		=	sources
SRC_SUBDIR	=	{$(P_SRC_DIR),$(BI_SRC_DIR),$(LIN_SRC_DIR),$(LEX_SRC_DIR),$(ERR_SRC_DIR),$(VAR_SRC_DIR)}
SOURCES		=	main.c \
				term_mode.c \
				word_tools.c \
				ft_init.c \
				env_tools.c \
				env_tools2.c \
				ft_find_exec.c \
				ft_find_exec_path.c \
				ft_free_data.c \
				signal_manager.c \
				meta.c \
				$(addprefix $(P_SRC_DIR)/,$(P_SOURCES)) \
				$(addprefix $(LEX_SRC_DIR)/,$(LEX_SOURCES)) \
				$(addprefix $(LIN_SRC_DIR)/,$(LIN_SOURCES)) \
				$(addprefix $(ERR_SRC_DIR)/,$(ERR_SOURCES)) \
				$(addprefix $(VAR_SRC_DIR)/,$(VAR_SOURCES)) \
				$(addprefix $(BI_SRC_DIR)/,$(BI_SOURCES)) \

SRCS		=	$(addprefix $(SRC_DIR)/,$(SOURCES)) \

OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

HDR_PATH	=	includes \
				libft/includes \

HDR_FLAG	=	$(addprefix -I ,$(HDR_PATH))

RM			=	rm -f

CLEAN		=	clean

all			:	libs
	@(($(MAKE) -q $(NAME) && echo "Your $(NAME) is up to date") || $(MAKE) $(NAME))

libs	:
	@cd $(LIB_PATH) && $(MAKE)

dep := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.d))
-include $(dep)

$(NAME)		:	$(LIBS) $(OBJS) Makefile
	@$(CC) $(CFLAGS) -ltermcap $(OBJS) $(LIBS) $(HDR_FLAG) -o $@
	@echo "$@ has been successfully created."

$(OBJS)		: $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HDR_FLAG) -o $@ -c $< -MMD -MP
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJ_DIR)	:
	@mkdir -p $@
	@mkdir -p $@/$(SRC_SUBDIR)

clean		:
	@$(RM) $(OBJS)
	@rm -Rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."

fclean		:	clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(NAME) exectutable and libft.a have been deleted."

re			:	fclean all

.PHONY: all libs clean fclean re
