/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:04:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/26 17:41:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>

size_t	ft_get_term_length(void)
{
	tgetent(NULL, getenv("TERM"));
	return (tgetnum("co"));
}

size_t	ft_get_term_hight(void)
{
	tgetent(NULL, getenv("TERM"));
	return (tgetnum("li"));
}
