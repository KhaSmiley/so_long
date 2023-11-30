/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ecp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:51:30 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/21 21:20:44 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_player(t_data *data)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				p++;
			j++;
		}
		j = 0;
		i++;
	}
	return (p);
}

int	count_exit(t_data *data)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	j = 0;
	e = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	return (e);
}

int	count_coins(t_data *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

int	find_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos_x = j;
				data->player_pos_y = i;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
