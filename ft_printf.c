/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:09:27 by tkulket           #+#    #+#             */
/*   Updated: 2022/10/10 14:13:31 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	va_list	args;
	char 	*tmp;
	char 	*dst;
	int	c;

	tmp = (char *)str;
	if (!tmp)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	while (i < ft_strlen(tmp))
	{
		if (tmp[i] == '%')
		{
			i++;
			if (tmp[i] == 'c')
			{
				c = va_arg(args, int);
				ft_putchar_fd(c, 1);
//				printf("c =%c\n",c);
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
				ft_putstr_fd(dst , 1);
				len += ft_strlen(dst);
			}
//			len = ft_checkflag (args);
//			i = va_arg(args, int);
//			len--;
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
