/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:44:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:22:34 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "shell.h"

static char		*ft_check_dir_for_exec(char *path)
{
	DIR				*dir;
	struct dirent	*dirdata;
	char			*res;

	res = NULL;
	if ((dir = opendir(path)))
	{
		while ((dirdata = readdir(dir)))
			if (dirdata->d_type, exec)
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

char			*ft_find_exec_path(t_data *data)
{
	size_t		i;
	char		**path;
	char		*res;

	if ((res = ft_get_env_var(env, "PATH")) && ft_strcmp(res, data->hash_path))
	{
		data->hash_path = res;
		ft_tab_free(data->hash);
		if (!(path = ft_strsplit(res, ':')))
			ft_crisis_exit(MALLOC_ERR);
		i = 0;
		while ((path[i]))
			ft_update_hash(data, path[i++]);
		ft_tabfree(path);
	}
	return (res);
}
