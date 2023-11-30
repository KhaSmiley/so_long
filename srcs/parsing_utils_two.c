/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:22 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/24 16:46:01 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_size(t_data *data)
{
	if (data->nb_line < 3 || data->len < 3 || data->nb_line > 15
		|| data->len > 30)
	{
		ft_printf("Error\nMap is too small or too big");
		return (FALSE);
	}
	return (TRUE);
}
