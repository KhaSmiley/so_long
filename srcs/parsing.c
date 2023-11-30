/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:57 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/26 19:23:11 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_rectangle(char *path, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile doesn't exist", FALSE));
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf("Error\nEmpty file"));
	while (line)
	{
		if (!line)
			break ;
		if (data->nb_line == 0)
			data->len = ft_strlen_until_char(line, '\n');
		data->len_line = ft_strlen_until_char(line, '\n');
		data->nb_line++;
		if (data->len_line != data->len)
			return (free(line), FALSE);
		free(line);
		line = get_next_line(fd);
	}
	fd = close(fd);
	return (free(line), data->nb_line);
}

char	**push_map_to_double_array(char *path, int nb_line, t_data *data)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_calloc((nb_line + 1), sizeof(char *));
	if (!map)
		return (NULL);
	while (i < nb_line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = ft_substr(line, 0, ft_strlen_until_char(line, '\n'));
		i++;
		free(line);
	}
	map[i] = NULL;
	return (map);
}

char	**check_to_push_map(char *path, t_data *data)
{
	int		size;
	char	**map;

	size = check_map_rectangle(path, data);
	if (size == FALSE)
	{
		ft_printf("Error\nMap is not a rectangle");
		return (NULL);
	}
	map = push_map_to_double_array(path, size, data);
	if (!map)
		return (NULL);
	return (map);
}

void	data_init(char **argv, t_data *data)
{
	data->nb_move = 0;
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->exit_pos_x = 0;
	data->exit_pos_y = 0;
	data->width = 64;
	data->height = 64;
	data->nb_line = 0;
	data->map = check_to_push_map(argv[1], data);
}

int	map_complete_check(char **argv, t_data *data)
{
	data_init(argv, data);
	if (!data->map)
		return (FALSE);
	data->nb_exit = count_exit(data);
	data->nb_coins = count_coins(data);
	data->nb_player = count_player(data);
	if (check_if_wrong_char_map(data) == FALSE)
		return (free_tab(data->map), FALSE);
	if (check_border_map(data) == FALSE)
		return (free_tab(data->map), FALSE);
	if (check_first_and_last_line(data) == FALSE)
		return (free_tab(data->map), FALSE);
	if (data->nb_exit != 1 || data->nb_coins == 0 || data->nb_player != 1)
	{
		ft_printf("Error\nWrong number of ECP");
		return (free_tab(data->map), FALSE);
	}
	if (start_flood_fill(data) == FALSE)
		return (free_tab(data->map), FALSE);
	if (check_size(data) == FALSE)
		return (free_tab(data->map), FALSE);
	else
		return (TRUE);
}
