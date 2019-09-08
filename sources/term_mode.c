/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:24:59 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/08 15:15:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>
#include <term.h>

void	raw_term_mode(void) //maybe save the termios struct of incoming shell to restore it ?
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag &= ~(ECHO | ECHOCTL | ICANON | ISIG);
//	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));
}

void	def_term_mode(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag |= (ECHO | ECHOCTL | ICANON | ISIG);
//	tattr.c_oflag |= (OPOST);
	tcsetattr(0, TCSADRAIN, &tattr);
}

void	toggle_sig_mode(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag ^= ISIG;
	tcsetattr(0, TCSADRAIN, &tattr);
}
