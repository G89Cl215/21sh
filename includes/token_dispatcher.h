/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dispatcher.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2019/09/12 12:35:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/12 17:00:17 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_DISPATCHER_H
# define TOKEN_DISPATCHER_H

# include "list.h"
# include "def.h"

typedef struct		s_token
{
	int				(*ft_is_token)(char *cmd_line, size_t *i, char eol_flag);
	t_arglist		*(*ft_next_token)(char *cmd_line, size_t *i, char *eol_flag);
}					t_token;



t_arglist			*ft_next_plain_token(char *str, size_t *len, char *flag);
int					ft_is_quoted_token(char *str, size_t *len, char flag);
t_arglist			*ft_next_quoted_token(char *str, size_t *len, char *flag);
int					ft_is_dquoted_token(char *str, size_t *len, char flag);
t_arglist			*ft_next_dquoted_token(char *str, size_t *len, char *flag);
int					ft_is_bquoted_token(char *str, size_t *len, char flag);
t_arglist			*ft_next_bquoted_token(char *str, size_t *len, char *flag);

#endif
