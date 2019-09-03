/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:40:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/03 11:47:31 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	ft_count_nl(char *cmd_line)
{
	size_t		nl_nbr;
	size_t		i;

	nl_nbr = 0;
	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\n')
			nl_nbr++;
		i++;
	}
	return (nl_nbr);
}

size_t		ft_get_line_form(const char *cmd_line)
{
	size_t		*line_form;
}
