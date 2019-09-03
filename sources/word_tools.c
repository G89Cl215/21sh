/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:18:59 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/03 19:59:59 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "def.h"
#include "word_tools.h"

size_t	ft_display_len(char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!((str[i] & bit_8) && !(str[i] & bit_7)))
			len++;
		i++;
	}
	return (len);
}

size_t	ft_next_word_start(char *str, size_t char_cursor)
{
	size_t			i;

	i = 0;
	str += char_cursor;
	while ((str[i]) && !(ft_isin(str[i], WORD_DELIM)))
		i++;
	while ((str[i]) && ft_isin(str[i], WORD_DELIM))
		i++;
	return (i);
}

size_t	ft_next_word_end(char *str, size_t char_cursor)
{
	size_t			i;

	i = 0;
	str += char_cursor;
	while (str[i] && ft_isin(str[i], WORD_DELIM))
		i++;
	while (str[i] && !(ft_isin(str[i], WORD_DELIM)))
		i++;
	return (i);
}

size_t	ft_prev_word_start(char *str, size_t char_cursor)
{
	size_t			i;

	i = 0;
	str += char_cursor;
	while (i < char_cursor && ft_isin(*(str - i - 1), WORD_DELIM))
		i++;
	while (i < char_cursor && !(ft_isin(*(str - i - 1), WORD_DELIM)))
		i++;
	return (i);
}

/*
size_t	ft_prev_word_end(char *str, size_t char_cursor)
{
	size_t			i;

	i = 0;
	str += char_cursor;
	while (i < char_cursor && ft_isin(*(str - i - 1), WORD_DELIM))
		i++;
	while (i < char_cursor && !(ft_isin(*(str - i - 1), WORD_DELIM)))
		i++;
	return (i);
}
*/

size_t	ft_cursor_conv_char_to_display(char *str, size_t char_cursor)
{
	size_t		i;
	size_t		display_cursor;

	i = 0;
	display_cursor = 0;
	while (i < char_cursor && str[i])
	{
		if (!((str[i] & bit_8) && !(str[i] & bit_7)))
			display_cursor++;
		i++;
	}
	return (display_cursor);
}
