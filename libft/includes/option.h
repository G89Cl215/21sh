/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:50:56 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/02 20:49:40 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# include <stdbool.h>
# define OPT "Raglnort1"

typedef struct	s_options
{
	int		l : 1;
}				t_options;

int				ft_option(char ***av, t_options *options);

#endif
