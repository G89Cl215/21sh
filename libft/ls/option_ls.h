/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_ls.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:56:40 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/01 13:56:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_LS_H
# define OPTION_LS_H

# include <stdbool.h>
# define OPT "Raglnort1"

typedef struct	s_options
{
	bool		l : 1;
	bool		r : 1;
	bool		rec : 1;
	bool		a : 1;
	bool		t : 1;
	bool		n : 1;
	bool		e : 1;
	bool		g : 1;
	bool		o : 1;
}				t_options;

int				ft_option_ls(char ***av, t_options *options);

#endif
