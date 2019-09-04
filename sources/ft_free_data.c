/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:07:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/04 12:33:30 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def.h"
#include "libft.h"

void	ft_free_data(t_data *data)
{
	ft_tabfree((data->env)->value);
	free(data->env);
	ft_free_dlist(&(data->history));
	if (((data->cursor)->line_form))
		ft_memdel((void **)(&((data->cursor)->line_form)));
	free(data->cursor);
}
