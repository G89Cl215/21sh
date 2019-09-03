/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:08:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 21:52:03 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_LIST_H
# define D_LIST_H

# define PAST_CMD		0
# define CUR_CMD		1

typedef struct				s_double_chained
{
	char					*cmd_line;
	int						status;
	struct s_double_chained	*prev;
	struct s_double_chained	*next;
}							t_dlist;

t_dlist						*ft_new_dnod(char *cmd_line, int status);
void						ft_relink(t_dlist *voyager, t_dlist *new_nod);
void						ft_revrelink(t_dlist *voyager, t_dlist *new_nod);
int							ft_free_dlist(t_dlist **lst);
t_dlist						*ft_del_dnod(t_dlist *nod_to_del);
void						ft_dmerge_sort(t_dlist **lst,
								int (*ft_cmp)(t_dlist *, t_dlist*), int flag);
int							ft_dlist_ascii_cmp(t_dlist *lst1, t_dlist *lst2);
void						ft_dlistadd_back(t_dlist **alst, t_dlist *new_nod);
void						ft_dlistadd_start(t_dlist **alst, t_dlist *new_nod);
t_dlist						*ft_reset_dlist_head(t_dlist *voyager);

#endif
