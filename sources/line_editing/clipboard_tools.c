/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:37:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:23:51 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "def.h"

void	ft_save_in_clipboard(t_data *data, char *to_save, size_t len)
{
	ft_bzero(data->clipboard, MAX_LINE);
	ft_memcpy(data->clipboard, to_save, len);
}
