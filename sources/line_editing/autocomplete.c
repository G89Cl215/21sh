/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:15:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:23:49 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_to_complete(t_cursor *cursor, char to_complete[MAX_LINE])
{
	size_t		char_cursor;
	size_t		word_count;

	char_cursor = 0;
	while (char_cursor < cursor->char_cursor)
	{

		char_cursor++;
	}


}

void	ft_autocomplete(t_data *data)
{
	char		code;
	char		to_complete[MAX_LINE];
	char		**results;
	t_cursor	*cursor;

	results = NULL;
	to_complete = NULL;
	cursor = data->cursor;
	if ((code = ft_to_complete(cursor, to_complete)) == EXEC_NAME)
		results = ft_exec_name_matches(to_complete);
	else if (code == ABS_PATH)
		results = ft_abs_path_matches(to_complete);
	else if (code == REL_PATH)
		results = ft_rel_path_matches(to_complete);
	if ((results))
		ft_display_results(results);
}
