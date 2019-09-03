/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:12:30 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 13:35:03 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_TOOLS_H
# define WORD_TOOLS_H

# define WORD_DELIM		" \t\n:"
# define bit_1				1
# define bit_2				2
# define bit_3				4
# define bit_4				8
# define bit_5				16
# define bit_6				32
# define bit_7				64
# define bit_8				128

size_t	ft_next_word_start(char *str, size_t char_cursor);
size_t	ft_next_word_end(char *str, size_t char_cursor);
size_t	ft_prev_word_start(char *str, size_t char_cursor);
size_t	ft_cursor_conv_char_to_display(char *str, size_t char_cursor);
size_t	ft_display_len(char *str);

#endif
