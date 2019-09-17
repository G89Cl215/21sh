/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:28:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 18:07:06 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include <stddef.h>
# include "def.h"

# define ENTER_CODE			0x0a
# define ESC_CODE			0x0b
# define UP_CODE			0x415b1b
# define DOWN_CODE			0x425b1b
# define RIGHT_CODE			0x435b1b
# define LEFT_CODE			0x445b1b
# define META_A_CODE		0x611b
# define META_B_CODE		0x621b
# define META_C_CODE		0x631b
# define META_D_CODE		0x641b
# define META_E_CODE		0x651b
# define META_F_CODE		0x661b
# define META_G_CODE		0x671b
# define META_H_CODE		0x681b
# define META_I_CODE		0x691b
# define META_J_CODE		0x6a1b
# define META_K_CODE		0x6b1b
# define META_L_CODE		0x6c1b
# define BACKSPACE_CODE		0x7f
# define META_BKSPC_CODE	0x7f1b
# define TAB_CODE			0x09
# define CTRL_A_CODE		0x01
# define CTRL_B_CODE		0x02
# define CTRL_C_CODE		0x03
# define CTRL_D_CODE		0x04
# define CTRL_E_CODE		0x05
# define CTRL_F_CODE		0x06
# define CTRL_G_CODE		0x07
# define CTRL_H_CODE		0x08
# define CTRL_I_CODE		0x09
# define CTRL_J_CODE		0x0a
# define CTRL_K_CODE		0x0b
# define CTRL_L_CODE		0x0c
# define CTRL_M_CODE		0x0d	//bizarrerie ici ?
# define CTRL_N_CODE		0x0e
# define CTRL_P_CODE		0x10
# define CTRL_R_CODE		0x12
# define CTRL_T_CODE		0x14
# define CTRL_U_CODE		0x15
# define CTRL_V_CODE		0x16
# define CTRL_W_CODE		0x17
# define CTRL_X_CODE		0x18
# define CTRL_Y_CODE		0x19
# define CTRL_Z_CODE		0x1a
# define DEL_CODE			0x7e335b1b
# define HOME_CODE			0x485b1b
# define END_CODE			0x465b1b

typedef struct		s_cap
{
	long			key_code;
	int				(*ft_)(t_data *data);
}					t_cap;

union				u_convert
{
	char			recieved[MAX_KEY_SIZE];
	long			code;
};

int					ft_enter(t_data *data);
int					ft_up_cursor(t_data *data);
int					ft_down_cursor(t_data *data);
int					ft_left_cursor(t_data *data);
int					ft_right_cursor(t_data *data);
int					ft_cut_cmd(t_data *data);
int					ft_backspace(t_data *data);
int					ft_end_of_stream(t_data *data);
int					ft_start_of_line(t_data *data);
int					ft_end_of_line(t_data *data);
int					ft_cut_from_cursor(t_data *data);
int					ft_clear_screen_key(t_data *data);
int					ft_to_next_word(t_data *data);
int					ft_to_next_end_word(t_data *data);
int					ft_to_prev_word(t_data *data);
int					ft_del_next_word(t_data *data);
int					ft_cut_prev_word(t_data *data);
int					ft_paste_clipboard(t_data *data);

#endif
