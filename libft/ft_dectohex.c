/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:11:48 by tkulket           #+#    #+#             */
/*   Updated: 2022/10/18 23:15:49 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_dectohex(unsigned int dec)
{
	unsigned int	hex;
	unsigned int	tmp;
	unsigned int	ram;
	size_t			i;
	size_t			len;
	
	hex = dec;
	len = 1;
	while (hex > 0)
	{
		hex /= 16;
		len++;	
	}
	hex = dec;
	i = 0;
	while (i < len)
	{
		ram = hex % 16;
		if (ram < 10)
			tmp = 48 + ram;
		else
			tmp = 55 + ram;
		hex  = hex / 16;
		i++;
	}
	return (tmp);
}
