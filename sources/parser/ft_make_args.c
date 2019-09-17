/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:55:03 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:37:07 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				**ft_make_args(t_arglist *arg_list)
{
	size_t		i;
	size_t		ac;
	char		**av;
	t_arglist	*voyager;

	i = 0;
	ac = ft_listlen(arg_list);
	voyager = arg_list;
	ft_mem_protect(av = (char**)malloc(sizeof(char*) * (ac + 1)));
	while (voyager && i < ac)
	{
		ft_mem_protect(av[i] = ft_strdup(voyager->arg));
		voyager = voyager->next;
		i++;
	}
	av[i] = NULL;
	return (av);
}


