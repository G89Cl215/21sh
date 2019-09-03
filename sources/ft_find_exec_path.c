/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_exec_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:28:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/09 03:27:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "minishell.h"

static char		*ft_check_dir_for_exec(char *path, char *exec)
{
	DIR				*dir;
	struct dirent	*dirdata;
	char			*res;

	res = NULL;
	if ((dir = opendir(path)))
	{
		while ((dirdata = readdir(dir)))
			if (!(ft_strcmp(dirdata->d_name, exec)))
			{
				closedir(dir);
				if (!(res = ft_strdup(path)))
					ft_crisis_exit(MALLOC_ERR);
				else
					return (res);
			}
		closedir(dir);
	}
	return (NULL);
}

char			*ft_find_exec_path(t_env *env, char *exec)
{
	size_t		i;
	char		**path;
	char		*res;

	if ((res = ft_get_env_var(env, "PATH")))
	{
		if (!(path = ft_strsplit(res, ':')))
			ft_crisis_exit(MALLOC_ERR);
		ft_strdel(&res);
		i = 0;
		while (path[i] && !(res))
			res = ft_check_dir_for_exec(path[i++], exec);
		ft_tabfree(path);
	}
	return (res);
}
