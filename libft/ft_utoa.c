/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:15:54 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/02 15:27:32 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insertchar_u(char *str, unsigned int n, size_t d)
{
/*
	if (n == INT_MIN)
	{
		str[0] = '-';
		str[1] = '2';
		ft_insertchar(str, 147483648, d);
	}
	else if (n < 0)
	{
		str[0] = '-';
		ft_insertchar(str, n * -1, d);
	}
*/
	if (n == 0)
		str[0] = '0';
	else if (n > 9)
	{
		ft_insertchar_u(str, n / 10, d - 1);
		str[d - 1] = (n % 10) + '0';
	}
	else
		str[d - 1] = (n % 10) + '0';
	return (str);
}

size_t	ft_countdigit_u(unsigned int n)
{
	size_t	d;

	d = 0;
/*	
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n *= -1;
		d++;
	}
*/
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_utoa(unsigned int n)
{
	char	*tmp;
	size_t	d;

	d = ft_countdigit_u(n);
	if (d == 0)
		d = 1;
	tmp = malloc(sizeof(char) * (d + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_insertchar_u(tmp, n, d);
	tmp[d] = '\0';
	return (tmp);
}
