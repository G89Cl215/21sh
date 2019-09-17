/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:14:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 17:24:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_priority(char *str)
{
	(void)str;
	return (1);
}

t_arglist			*ft_priority_meta(t_arglist *tokens)
{
	t_arglist	*res;

	res = NULL;
	while ((tokens))
	{
		if (tokens->delim == META
		&& (!(res) || ft_priority(tokens->arg) < ft_priority(res->arg)))
			res = tokens;
		tokens = tokens->next;
	}
	return (res);
}
