/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:12:12 by kboulkri          #+#    #+#             */
/*   Updated: 2023/09/30 21:16:33 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	pf_strlen(char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	pf_putnbr_base(unsigned long nb, char *base, int *len)
{
	if (nb >= pf_strlen(base))
	{
		pf_putnbr_base(nb / pf_strlen(base), base, len);
	}
	*len += pf_putchar(base[nb % pf_strlen(base)]);
}

void	pf_convert_base(unsigned long nbr, char param, int *len)
{
	char	*base[3];

	base[0] = "0123456789";
	base[1] = "0123456789abcdef";
	base[2] = "0123456789ABCDEF";
	if (param == 'u')
		pf_putnbr_base(nbr, base[0], len);
	else if (param == 'x')
		pf_putnbr_base(nbr, base[1], len);
	else if (param == 'X')
		pf_putnbr_base(nbr, base[2], len);
	else if (param == 'p')
	{
		if (nbr == 0)
		{
			*len += write(1, "(nil)", 5);
			return ;
		}
		*len += write(1, "0x", 2);
		pf_putnbr_base(nbr, base[1], len);
	}
}
