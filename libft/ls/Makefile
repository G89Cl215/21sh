# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/04/15 13:52:54 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls

LIB_LIST_PTH=	list_lib
LIB_LIST	=	list_lib.a

LIB 		=	$(addprefix $(LIB_LIST_PTH)/,$(LIB_LIST))

DIR_O		=   obj

SRCS	 	=	ft_ls.c \
				recursive_call.c \
				get_padding_size.c \
				parsing.c \
				parse_display.c\
				display.c \
				display_tools.c \
				extract_data.c \
				ft_long_display.c \
				read_and_stock_ls.c \
				sort.c \
				option_ls.c \

OBJS    	=   $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

HDR_DIR		=	../includes\
				list_lib\
				.

HDR			=	../includes/option.h \
				../includes/libft.h \
				list_lib/ls_list.h \
				ft_ls.h

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	$(addprefix -I ,$(HDR_DIR))

all : $(NAME)

$(LIB_LIST_PTH)/$(LIB_LIST) : 
	@echo "Compiling Ls List Library"
	@make -C $(LIB_LIST_PTH)

$(NAME) : $(LIB) $(OBJS) $(HDR) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) ../libft.a -o $(NAME) $(HDR_FLAG)
	@echo "ft_ls has been successfully created."

$(DIR_O) :
	@mkdir -p $(DIR_O)

$(OBJS) : $(DIR_O)/%.o : %.c | $(DIR_O)
	$(CC) $(CFLAGS) -o $(DIR_O)/$*.o -c $<
	@echo " \t \t \t \t \t \t \t \t [OK]  \r $*  \r "

clean :
	@$(RM) $(OBJS)
	@rm -Rf $(DIR_O)
	@make clean -C $(LIB_LIST_PTH)
	@echo "All .o files of ft_ls have been deleted."

fclean :   clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_LIST_PTH)
	@echo "ft_ls and libft.a have been deleted."

re  :   fclean all

.PHONY: all clean fclean re lib_msg lis_msg
