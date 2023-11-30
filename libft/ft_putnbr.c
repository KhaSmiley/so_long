/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:17:05 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/07 18:33:35 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_putnbr(int n, int *len)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		*len += pf_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		pf_putnbr(nb / 10, len);
	}
	*len += pf_putchar((nb % 10) + '0');
}

void	pf_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*len += pf_putchar(str[i]);
		i++;
	}
}

int	pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
