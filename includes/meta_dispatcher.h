/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_dispatcher.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:53:35 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 20:15:21 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_DISPATCHER_H
# define META_DISPATCHER_H

# define R_REDIR_APPEND_PRIO	3
# define L_REDIR_APPEND_PRIO	3
# define R_REDIR_PRIO			3
# define L_REDIR_PRIO			2
# define SEMI_COL_PRIO			0
# define LOGIC_AND_PRIO			1
# define AMPERSAND_PRIO			???????
# define LOGIC_OR_PRIO			1
# define PIPE_PRIO				2

typedef struct			s_meta
{
	char				*meta;
	char				flag;
	int					priority;
	//pointeur sur fonction (*ft_meta)();
}						t_meta;

ft_pipe();

#endif
