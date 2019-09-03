# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2019/08/29 11:43:20 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

SRCFILE	=	ft_dlistadd.c\
			ft_new_dnod.c\
			ft_free_dlist.c\
			ft_relink.c\
			ft_revrelink.c\
			ft_dmerge_sort.c\
			ft_ascii_cmp.c\
			ft_del_dnod.c \
			ft_reset_dlist_head.c \
			ft_listadd.c \
			ft_listadd_back.c \
			ft_listfree.c \
			ft_listfreeone.c \
			ft_listnew.c \
			ft_listlen.c \


SRCDIR	=	./
SRC		=	$(addprefix $(SRCDIR),$(SRCFILE))
HDR_DIR	=	../includes
CFLAGS	+=	$(addprefix -I ,$(HDR_DIR))	

OBJDIR	=	obj
OBJ		=	$(addprefix $(OBJDIR)/,$(SRCFILE:.c=.o))

NAME	=	list_lib.a

.PHONY: all re clean fclean query

all				:
	@($(MAKE) -q query && echo "LIBFT : Your List module is up to date") || $(MAKE) query

query			: $(NAME)

$(NAME)			: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "LIBFT : Your list_lib.a is ready"

$(OBJ)			: $(OBJDIR)/%.o : %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -o $(OBJDIR)/$*.o -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJDIR)		:
	@/bin/mkdir $(OBJDIR)

clean			:
	@/bin/rm $(OBJ) 2>/dev/null || true
	@/bin/rm -R $(OBJDIR) 2>/dev/null || true

fclean			: clean
	@/bin/rm -f $(NAME)

re				: fclean all
