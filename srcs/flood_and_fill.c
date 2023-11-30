/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:36:27 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/26 21:45:40 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_way(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				ft_printf("Error\nMap cannot be finished");
				return (FALSE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int	find_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos_x = j;
				data->player_pos_y = i;
				return (TRUE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}

void	flood_fill_map(char **map, t_point size, t_point cur)
{
	int	i;

	i = 0;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (map[cur.y][cur.x] != '0' && map[cur.y][cur.x] != 'C'
			&& map[cur.y][cur.x] != 'E' && map[cur.y][cur.x] != 'P'))
		return ;
	map[cur.y][cur.x] = 'F';
	flood_fill_map(map, size, (t_point){cur.x - 1, cur.y});
	flood_fill_map(map, size, (t_point){cur.x + 1, cur.y});
	flood_fill_map(map, size, (t_point){cur.x, cur.y - 1});
	flood_fill_map(map, size, (t_point){cur.x, cur.y + 1});
}

int	flood_fill(char **map, t_point size, t_point begin)
{
	flood_fill_map(map, size, begin);
	return (find_way(map));
}

int	start_flood_fill(t_data *data)
{
	t_point	size;
	t_point	begin;
	int		i;
	char	**map;
	int		result;

	i = 0;
	map = ft_calloc(sizeof(char *), data->nb_line + 1);
	while (data->map[i] != NULL)
	{
		map[i] = ft_substr(data->map[i], 0, data->len_line);
		i++;
	}
	map[i] = NULL;
	size.x = data->len_line;
	size.y = data->nb_line;
	find_player_position(data);
	begin.x = data->player_pos_x;
	begin.y = data->player_pos_y;
	result = flood_fill(map, size, begin);
	if (result == FALSE)
		return (free_tab(map), FALSE);
	return (free_tab(map), TRUE);
}
