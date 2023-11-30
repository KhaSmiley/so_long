/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:20:00 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/09 18:20:10 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_until_char(const char *str, char c)
{
	size_t	l;

	l = 0;
	while (str[l] != c && str[l] != '\0')
	{
		l++;
	}
	return (l);
}