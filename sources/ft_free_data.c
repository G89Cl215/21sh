/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:07:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 17:19:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def.h"
#include "libft.h"

int		ft_free_data(t_data *data)
{
	int		status;

	status = data->status;
	ft_tabfree((data->env)->value);
	free(data->env);
	if ((data->env_exec)->value != NULL)
		ft_tabfree((data->env_exec)->value);
	free(data->env_exec);
	ft_free_dlist(&(data->history));
	if (((data->cursor)->line_form))
		ft_memdel((void **)(&((data->cursor)->line_form)));
	free(data->cursor);
	free(data->term_def_setting);
	return (status);
}
