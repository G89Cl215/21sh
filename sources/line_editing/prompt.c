/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:34:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:26:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "word_tools.h"

void	ft_display_prompt(char flag)
{
	if (flag == NEWLINE)
		ft_putstr(NL_PROMPT);
	else if (flag == QUOTES)
		ft_putstr(QUOTES_PROMPT);
	else if (flag == DQUOTES)
		ft_putstr(DQUOTES_PROMPT);
	else if (flag == BQUOTES)
		ft_putstr(BQUOTES_PROMPT);
	else
		ft_printf("%s$> ", NAME);
}

size_t	ft_prompt_len(char flag)
{
	if (flag == NEWLINE)
		return (ft_display_len(NL_PROMPT));
	if (flag == QUOTES)
		return (ft_display_len(QUOTES_PROMPT));
	if (flag == DQUOTES)
		return (ft_display_len(DQUOTES_PROMPT));
	if (flag == BQUOTES)
		return (ft_display_len(BQUOTES_PROMPT));
	return (ft_display_len(NAME) + 3);
}
