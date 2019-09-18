/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:35:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/18 03:37:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>

#include <stdio.h>

#include <stdlib.h>
#include "cap_dispatcher.h"
#include "line_edit.h"
#include "d_list.h"
#include "libft.h"
#include "shell.h"

t_cap		g_termcap[] =
{
	{ENTER_CODE, &ft_enter},
	{META_B_CODE, &ft_to_prev_word},
	{META_F_CODE, &ft_to_next_word},
	{META_L_CODE, &ft_to_next_end_word},
	{META_D_CODE, &ft_del_next_word},
	{META_K_CODE, &ft_clear_screen_key},
	{UP_CODE, &ft_up_cursor},
	{CTRL_P_CODE, &ft_up_cursor},
	{DOWN_CODE, &ft_down_cursor},
	{RIGHT_CODE, &ft_right_cursor},
	{CTRL_F_CODE, &ft_right_cursor},
	{LEFT_CODE, &ft_left_cursor},
	{CTRL_B_CODE, &ft_left_cursor},
	{BACKSPACE_CODE, &ft_backspace},
	{META_BKSPC_CODE, &ft_cut_prev_word},
	{CTRL_H_CODE, &ft_backspace},
//	{TAB_CODE, &ft_autocomplete},
/*	{CTRL_\_CODE, &ft_sig_quit_program},
*/	{CTRL_A_CODE, &ft_start_of_line},
	{CTRL_E_CODE, &ft_end_of_line},
	{CTRL_D_CODE, &ft_end_of_stream},
	{CTRL_K_CODE, &ft_cut_from_cursor},
	{CTRL_L_CODE, &ft_clear_screen_key},
/*	{CTRL_R_CODE, &ft_search_history},*/
//	{CTRL_T_CODE, &ft_swap_char}, //la difficulte c'est l'unicode
	{CTRL_U_CODE, &ft_cut_cmd},
	{CTRL_W_CODE, &ft_cut_prev_word},
	{CTRL_Y_CODE, &ft_paste_clipboard},
//	{CTRL_U_CODE, &ft_clear_cmd},
//	{DEL_CODE, &ft_delete_key},
	{HOME_CODE, &ft_start_of_line},
	{END_CODE, &ft_end_of_line},
	{0, NULL}
};

int		ft_termcap(char buff[MAX_KEY_SIZE], t_data *data)
{
	union u_convert		conv;
	size_t				i;

	i = 0;
	ft_memcpy(conv.recieved, buff, MAX_KEY_SIZE);
//	print_bytes(buff, MAX_KEY_SIZE);
//	printf("%li\n\r", conv.code);
	while ((g_termcap[i].key_code))
	{
		if (g_termcap[i].key_code == conv.code)
			return (g_termcap[i].ft_(data));
		i++;
	}
	return (!(ft_isunicode((unsigned char *)buff)));
}
