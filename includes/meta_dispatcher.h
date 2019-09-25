/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_dispatcher.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:53:35 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/25 13:17:48 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_DISPATCHER_H
# define META_DISPATCHER_H

# include "def.h"

# define R_REDIR_APPEND_PRIO	3
# define L_REDIR_APPEND_PRIO	3
# define R_REDIR_PRIO			3
# define L_REDIR_PRIO			2
# define SEMI_COL_PRIO			0
# define LOGIC_AND_PRIO			1
/*# define AMPERSAND_PRIO			???????*/
# define LOGIC_OR_PRIO			1
# define PIPE_PRIO				2

t_ft_meta		ft_r_redir_append;
t_ft_meta		ft_r_redir;
t_ft_meta		ft_l_redir_append;
t_ft_meta		ft_l_redir;
t_ft_meta		ft_semi_col;
t_ft_meta		ft_logic_and;
t_ft_meta		ft_logic_or;
t_ft_meta		ft_ampersand;
t_ft_meta		ft_pipe;

#endif
