/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:04 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/24 16:37:00 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	exit_and_free(t_data *data)
{
	free_tab(data->map);
	if (data->texture[0])
		mlx_destroy_image(data->mlx_ptr, data->texture[0]);
	if (data->texture[1])
		mlx_destroy_image(data->mlx_ptr, data->texture[1]);
	if (data->texture[2])
		mlx_destroy_image(data->mlx_ptr, data->texture[2]);
	if (data->texture[3])
		mlx_destroy_image(data->mlx_ptr, data->texture[3]);
	if (data->texture[4])
		mlx_destroy_image(data->mlx_ptr, data->texture[4]);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}
