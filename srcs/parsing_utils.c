/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:04:07 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/21 21:22:43 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ext_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	i--;
	if (argv[i] == 'r')
	{
		i--;
		if (argv[i] == 'e')
		{
			i--;
			if (argv[i] == 'b')
			{
				i--;
				if (argv[i] == '.')
					return (TRUE);
			}
		}
	}
	ft_printf("Erreur\nWrong extension\n");
	return (FALSE);
}

int	check_if_wrong_char_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'P')
			{
				ft_printf("Erreur\nWrong char in map\n");
				return (FALSE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int	check_first_and_last_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][i] != '\0' && data->map[0][i] != '\n')
	{
		if (data->map[0][i] != '1')
		{
			ft_printf("Erreur\nTop map is not closed\n");
			return (FALSE);
		}
		i++;
	}
	while (data->map[data->nb_line - 1][j] != '\0' && data->map[data->nb_line
		- 1][j] != '\n')
	{
		if (data->map[data->nb_line - 1][j] != '1')
		{
			ft_printf("Erreur\nBottom map is not closed\n");
			return (FALSE);
		}
		j++;
	}
	return (TRUE);
}

int	check_border_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i][0] != '1' || data->map[i][data->len_line - 1] != '1')
		{
			ft_printf("Erreur\nMap is not closed\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	find_exit_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'E')
			{
				data->exit_pos_x = j;
				data->exit_pos_y = i;
				return (TRUE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}
