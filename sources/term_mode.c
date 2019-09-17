/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:24:59 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:27:42 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "def.h"

void	raw_term_mode()
{
	t_ermios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | /*ECHOCTL |*/ ICANON | ISIG);
//	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));
}

void	restore_term_mode(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSANOW, data->term_def_setting); //valgrind error : ioctl point to uninitialized byte. STDIN_FILENO ?
}

void	toggle_sig_mode(void)
{
	t_ermios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag ^= ISIG;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
}
