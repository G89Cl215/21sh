/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:38:41 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/03 15:33:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "def.h"

# define PROMPT				"ici le πromπt: "
# define EXIT_SIG 2
# define ENTER_SIG 3

int			ft_termcap(char *buff, t_data *data);
void		ft_init_cursor(t_cursor *cursor, char flag);
void		ft_init_data(t_data *data);
void		ft_cursor_reset(size_t ref);
void		ft_position_cursor(t_cursor *cursor);
void		ft_clear_line(t_cursor *cursor);
int			ft_pc(int c);
void		ft_display_prompt(char flag);
size_t		ft_prompt_len(char flag);
void		ft_update_line(t_cursor *cursor, char *buff);
void		raw_term_mode(void);
void		def_term_mode(void);
size_t		ft_get_term_length(void);
size_t		ft_get_term_hight(void);
void		ft_reajust_cursor_wrap(t_cursor *cursor, int flag);
size_t		*ft_get_line_form(const char *cmd_line);
void		ft_clean_history(t_dlist **history);
void		ft_load_history(t_data *data);
void		ft_save_history(t_data *data, char flag);
void		ft_save_in_clipboard(t_data *data, char *to_save, size_t len);
void		ft_position_cursor(t_cursor *cursor);
int			ft_get_next_cmd_line(t_data *data);

void	print_bytes(void *ptr, int size);

#endif
