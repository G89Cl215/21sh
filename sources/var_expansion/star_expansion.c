/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expanding_star.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:24:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:27:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "shell.h"

t_arglist	*ft_match_dir(char *dir_name, char *to_match)
{
	char			*res;
	DIR				*dir;
	struct dirent	*dirdata;
	t_arglist		*first_stage;

	res = NULL;
	first_stage = NULL;
	if ((dir = opendir(dir_name)))
	{
		while ((dirdata = readdir(dir)))
			if ((dirdata->d_name)[0] != '.'
			&& ft_match(dirdata->d_name, to_match, 0))
			{
				if ((!(ft_strcmp(dir_name, "/"))
				&& !(res = ft_build_path(ft_strnew(0), dirdata->d_name)))
				|| !(res = ft_strdup(dirdata->d_name)))
					ft_crisis_exit(MALLOC_ERR);
				ft_listadd_back(&first_stage, ft_listnewstr(res, 1, NO_DELIM));
				free(res);
			}
		closedir(dir);
	}
	return (first_stage);
}

static void	ft_match_in_dir(t_arglist *new_stage, DIR *dir, char *dir_name,
																char *to_match)
{
	struct dirent	*dirdata;
	char			*res;

	res = NULL;
	while ((dirdata = readdir(dir)))
		if ((dirdata->d_name)[0] != '.'
		&& ft_match(dirdata->d_name, to_match, 0))
		{
			if (!(res = ft_build_path(ft_strdup(dir_name), dirdata->d_name)))
				ft_crisis_exit(MALLOC_ERR);
			ft_listadd_back(&new_stage, ft_listnewstr(res, 1, NO_DELIM));
			free(res);
		}
	closedir(dir);
}

t_arglist	*ft_match_stages(t_arglist *match_dir, char *to_match)
{
	DIR				*dir;
	t_arglist		*voyager;
	t_arglist		*new_stage;

	new_stage = NULL;
	voyager = match_dir;
	while ((voyager))
	{
		if ((dir = opendir(voyager->arg)))
			ft_match_in_dir(new_stage, dir, voyager->arg, to_match);
		voyager = voyager->next;
	}
	ft_listfree(&match_dir);
	return (new_stage);
}

void		ft_no_match_err(t_arglist *arg, int *status)
{
	*status = NO_MATCH;
	ft_printf("%s: No match for %s.\n", NAME, arg->arg);
}

int			ft_star_match_expand(t_arglist *arg, int *status)
{
	t_arglist	*matches;
	char		**dir_split;
	size_t		len;
	size_t		i;

	matches = NULL;
	if (!(dir_split = ft_strsplit(arg->arg, '/')))
		ft_crisis_exit(MALLOC_ERR);
	len = ft_tablen(dir_split);
	i = 1;
	matches = ft_match_dir(arg->arg[0] == '/' ? "/" : ".", dir_split[0]);
	while (i < len && (matches = ft_match_stages(matches, dir_split[i])))
		i++;
	ft_tabfree(dir_split);
	i = ft_listlen(matches);
	if ((matches))
	{
		ft_listadd_back(&matches, arg->next);
		free(arg->arg);
		*arg = *matches;
		free(matches);
	}
	else
		ft_no_match_err(arg, status);
	return (i - 1);
}
