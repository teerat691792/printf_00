/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:09:27 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/02 19:19:18 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	ft_flag(va_list tmp, ...)
{
//	size_t		i;

//	i = 0;
//	while (str[i])
//	{
		ft_putchar_fd(str[0], 1);
//		i++;
//	}
	return (1);
}
*/

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	i;
	char	*unbr;
	va_list	args;
	char 	*tmp;
	char 	*dst;
	char 	*nbr;
	int	c;

	tmp = (char *)str;
	if (!tmp)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	unsigned int j = ft_strlen(tmp);
	while (i < j)
	{
		if (tmp[i] == '%')
		{
			i++;
			if (tmp[i] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
			} 
			else if (tmp[i] == 'c')
			{
				c = va_arg(args, int);
				ft_putchar_fd(c, 1);
				len++;
			}
			else if (tmp[i] == 's')
			{
				dst = va_arg(args, char *);
				if (!dst)
				{
					ft_putstr_fd("(null)", 1);
					len += ft_strlen("(null)");
				}
				ft_putstr_fd(dst, 1);
				len += ft_strlen(dst);
			}
			else if (tmp[i] == 'd' || tmp[i] == 'i')
			{
				nbr = ft_itoa(va_arg(args, int));
				ft_putstr_fd(nbr, 1);
				len += ft_strlen(nbr);
				free(nbr);
			}
			else if (tmp[i] == 'u')
			{
				unbr = ft_utoa(va_arg(args, unsigned int));
				ft_putstr_fd(unbr, 1);
				len += ft_strlen(unbr);
				free(unbr);
			}
			else if (tmp[i] == 'p')
			{
				unbr = ft_address(va_arg(args, unsigned long));
				write (1, "0x", 2);
				ft_putstr_fd(unbr, 1);
				len = len + ft_strlen(unbr) + 2;
				free(unbr);
			}
			else if (tmp[i] == 'x')
			{
				unbr = ft_htoa(va_arg(args, unsigned int));
				ft_putstr_fd(unbr, 1);
				len += ft_strlen(unbr);
				free(unbr);
			}
			else if (tmp[i] == 'X')
			{
				unbr = ft_htoa(va_arg(args, unsigned int));
				unbr = ft_toupper_h(unbr);
				ft_putstr_fd(unbr, 1);
				len += ft_strlen(unbr);
				free(unbr);
			}
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		} 
		i++;
	}
	va_end(args);
	return (len);

}
