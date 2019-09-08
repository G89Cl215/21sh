# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/09/04 17:41:40 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra
#-fsanitize=address

NAME		=	parsing_test

LIB_PATH	=	libft
LIB			=	libft.a

LIBS		=	$(LIB_PATH)/$(LIB) \

OBJ_DIR		=	obj

SRC_DIR	=	sources
SOURCES		=	ft_get_next_cmd_line.c \
				ft_get_line_form.c \
				minishell.c \
				termcaps.c \
				reprint_line.c \
				ft_enter.c \
				term_mode.c \
				prompt.c \
				cursor_tools.c \
				get_term_size.c \
				history.c \
				line_edit.c \
				line_edit_cut.c \
				ctrl_keys.c \
				word_tools.c \
				clipboard_tools.c \
				cursor_moves.c \
				fast_cursor_moves.c \
				ft_init.c \
				env_tools.c \
				env_tools2.c \
				expansion_tools.c\
				ft_find_exec.c \
				ft_find_exec_path.c \
				ft_built_in.c \
				ft_built_in_cd.c \
				ft_built_in_env.c \
				ft_built_in_env2.c \
				gestion_de_crise.c \
				parsing_command.c \
				parsing_expanding.c \
				parsing_expanding_dollar.c \
				parsing_expanding_star.c \
				parsing_expanding_tilde.c \
				parsing_tokenizing.c \
				parsing_token_tools.c \
				perror1.c \
				perror2.c \
				ft_free_data.c \

SRCS		=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJS		=	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))


HEADERS		=	includes/cursor.h \
				includes/dispatcher.h \

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
