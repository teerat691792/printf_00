/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:24:33 by tkulket           #+#    #+#             */
/*   Updated: 2022/10/19 00:31:43 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insertchar_h(char *str, unsigned int n, size_t d)
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
	else if (n > 10)
	{
		ft_insertchar_h(str, n / 16, d - 1);
//		str[d - 1] = (n % 16) + '0' + 55;
		str[d - 1] = (n % 16) + 87;
	}
	else
//		str[d - 1] = (n % 16) + '0' + 48;
		str[d - 1] = (n % 16) + 48;
	return (str);
}

size_t	ft_countdigit_h(int n)
{
	size_t	d;

/*
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n *= -1;
		d++;
	}
*/
	d = 0;
	while (n > 0)
	{
		n /= 16;
		d++;
	}
	return (d);
}

char	*ft_htoa(unsigned int n)
{
	char			*tmp;
	size_t			d;
//	unsigned int	hex;
	
//	hex = ft_dectohex(n);	
//	d = ft_countdigit_h(hex);
	d = ft_countdigit_h(n);
	if (d == 0)
		d = 1;
	tmp = malloc(sizeof(char) * (d + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_insertchar_h(tmp, n, d);
	tmp[d] = '\0';
	return (tmp);
}
