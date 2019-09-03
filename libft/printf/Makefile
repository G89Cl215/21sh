# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 16:10:22 by tgouedar          #+#    #+#              #
#    Updated: 2019/08/08 17:17:24 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libprintf.a

HDR_DIR	=   ../includes \

SRCS	=   ft_printf.c \
			display_result.c \
			extract_from_pattern.c \
			conv_char_printf.c \
			conv_float1_printf.c \
			conv_float2_printf.c \
			conv_int_printf.c \
			conv_ubase_printf.c \
			conv_unicode_printf.c \
			float_conv_tools.c \
			crisis_room.c \
			padding_types.c \
			padding_flags.c \
			padding_prec.c \
			padding_negativ.c \
			padding_positiv.c \
			padding_positiv2.c \
			padding_floats.c \
			padding_prefix.c \
			padding_prefix2.c \
			padding_spaces.c \
			padding_zero.c \
			padding_zero2.c \
			gestion_t_pattern.c \
			parsing_pos1.c \
			parsing_pos2.c \
			parsing_extract_pattern.c \
			parsing_pattern_detect.c \
			parsing_conv.c \

OBJ_DIR	=	obj

OBJ_FILE=	$(SRCS:.c=.o)
OBJS    =	$(addprefix $(OBJ_DIR)/,$(OBJ_FILE))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra
CFLAGS	+=	$(addprefix -I ,$(HDR_DIR))

all			:
	@($(MAKE) -q $(NAME) && echo "LIBFT : Your Printf module is up to date") || $(MAKE) $(NAME)

$(NAME)		: $(OBJS) Makefile
	@ar rc $(NAME) $(OBJS)
	@echo "LIBFT : $(NAME) has been successfully created."

$(OBJS)		: $(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/$*.o -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJ_DIR)		:
	@mkdir -p $(OBJ_DIR) 

clean   :
	@rm -Rf $(OBJ_DIR)
	@echo "All .o files of $(NAME) have been deleted."

fclean  :   clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been deleted."

re      :   fclean all

.PHONY: all clean fclean re
