/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:24:57 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/21 21:25:42 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_player_position(t_data *data, int new_x, int new_y, char n)
{
	data->nb_move++;
	data->map[data->player_pos_y][data->player_pos_x] = '0';
	data->player_pos_x = new_x;
	data->player_pos_y = new_y;
	data->map[data->player_pos_y][data->player_pos_x] = n;
}

void	move_up(t_data *data)
{
	int	y;

	find_player_pos(data);
	y = data->player_pos_y - 1;
	if (y == data->nb_line || data->map[y][data->player_pos_x] == '1')
		return ;
	if (data->map[y][data->player_pos_x] == 'C')
		data->nb_coins--;
	if (data->map[y][data->player_pos_x] == 'E')
	{
		if (data->nb_coins == 0)
			exit_and_free(data);
		else
			return ;
	}
	update_player_position(data, data->player_pos_x, y, 'P');
	ft_printf("nb_move = %d\n", data->nb_move);
	display_map(data);
}

void	move_down(t_data *data)
{
	int	y;

	find_player_pos(data);
	y = data->player_pos_y + 1;
	if (y == data->nb_line || data->map[y][data->player_pos_x] == '1')
		return ;
	if (data->map[y][data->player_pos_x] == 'C')
		data->nb_coins--;
	if (data->map[y][data->player_pos_x] == 'E')
	{
		if (data->nb_coins == 0)
			exit_and_free(data);
		else
			return ;
	}
	update_player_position(data, data->player_pos_x, y, 'P');
	ft_printf("nb_move = %d\n", data->nb_move);
	display_map(data);
}

void	move_left(t_data *data)
{
	int	x;

	find_player_pos(data);
	x = data->player_pos_x - 1;
	if (x == data->len_line || data->map[data->player_pos_y][x] == '1')
		return ;
	if (data->map[data->player_pos_y][x] == 'C')
		data->nb_coins--;
	if (data->map[data->player_pos_y][x] == 'E')
	{
		if (data->nb_coins == 0)
			exit_and_free(data);
		else
			return ;
	}
	update_player_position(data, x, data->player_pos_y, 'P');
	ft_printf("nb_move = %d\n", data->nb_move);
	display_map(data);
}

void	move_right(t_data *data)
{
	int	x;

	find_player_pos(data);
	x = data->player_pos_x + 1;
	if (x == data->len_line || data->map[data->player_pos_y][x] == '1')
		return ;
	if (data->map[data->player_pos_y][x] == 'C')
		data->nb_coins--;
	if (data->map[data->player_pos_y][x] == 'E')
	{
		if (data->nb_coins == 0)
			exit_and_free(data);
		else
			return ;
	}
	update_player_position(data, x, data->player_pos_y, 'P');
	ft_printf("nb_move = %d\n", data->nb_move);
	display_map(data);
}
