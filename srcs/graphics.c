/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:21:28 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/26 21:58:28 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65362 || keysym == 119)
		move_up(data);
	if (keysym == 65364 || keysym == 115)
		move_down(data);
	if (keysym == 65361 || keysym == 97)
		move_left(data);
	if (keysym == 65363 || keysym == 100)
		move_right(data);
	if (keysym == 65307)
		exit_and_free(data);
	return (0);
}

void	init_image(t_data *data)
{
	int	i;

	i = 0;
	data->texture[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/P.xpm",
			&(data->width), &(data->height));
	data->texture[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/C.xpm",
			&(data->width), &(data->height));
	data->texture[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/E.xpm",
			&(data->width), &(data->height));
	data->texture[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/W.xpm",
			&(data->width), &(data->height));
	data->texture[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/BG.xpm", &(data->width), &(data->height));
	while (i < 5)
	{
		if (data->texture[i] == NULL)
		{
			write(2, "Error\nImage no initialise", 26);
			exit_and_free(data);
		}
		i++;
	}
}

void	display_map_2(t_data *data, int *i, int *j)
{
	if (data->map[*j][*i] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture[0],
			(*i * 64), (*j * 64));
	if (data->map[*j][*i] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture[1],
			(*i * 64), (*j * 64));
	if (data->map[*j][*i] == 'E' && data->nb_coins != 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture[4],
			(*i * 64), (*j * 64));
	if (data->map[*j][*i] == 'E' && data->nb_coins == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture[2],
			(*i * 64), (*j * 64));
	if (data->map[*j][*i] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture[3],
			(*i * 64), (*j * 64));
	if (data->map[*j][*i] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture[4],
			(*i * 64), (*j * 64));
}

void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			display_map_2(data, &i, &j);
			i++;
		}
		i = 0;
		j++;
	}
}

int	main_graphics(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	init_image(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->len * 64, data->nb_line
			* 64, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	display_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &exit_and_free,
		data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
