/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_dispatcher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:26:43 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/04 19:07:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_DISPATCHER_H
# define ERR_DISPATCHER_H

typedef struct		s_err
{
	int				status;
	void			(*ft_perror)(char **av, char *err);
}					t_err;

void				ft_not_a_cmd(char **av, char *err);
void				ft_invalid_opt(char **av, char *err);
void				ft_target_not_found(char **av, char *err);
void				ft_arg_nbr_high(char **av, char *err);
void				ft_arg_nbr_low(char **av, char *err);
void				ft_arg_not_num(char **av, char *err);

#endif
