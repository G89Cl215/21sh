/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:15:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/09 20:42:24 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_autocomplete(t_data *data)
{
	char		code;
	char		*to_complete;
	char		**results;
	t_cursor	*cursor;

	results = NULL;
	to_complete = NULL;
	cursor = data->cursor;
	if ((code = ft_to_complete(cursor, to_complete)) == EXEC_NAME)
		results =
	else if (code == ABS_PATH)
	{}
	else if (code == REL_PATH)
	{}
	if ((results))
		ft_display_results(results);
}
