/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_dispatcher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:28:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:30:58 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BI_DISPATCHER_H
# define BI_DISPATCHER_H

# include <stddef.h>
# include "def.h"

typedef struct		s_dispatcher
{
	char			*name;
	int				(*ft_)(t_env *env, char **av, int *status);
	void			(*ft_usage)(void);
}					t_dispatcher;

int					ft_echo(t_env *env, char **av, int *status);
int					ft_cd(t_env *env, char **av, int *status);
void				ft_cd_usage(void);
int					ft_env(t_env *env, char **av, int *status);
int					ft_setenv(t_env *env, char **av, int *status);
void				ft_set_usage(void);
int					ft_unsetenv(t_env *env, char **av, int *status);
int					ft_exit(t_env *env, char **av, int *status);

#endif
