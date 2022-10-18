/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:24:13 by tkulket           #+#    #+#             */
/*   Updated: 2022/10/18 23:37:52 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
void	print_int(int num, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, num);
	for (i = 0; i < num; i++)
	{
		result = va_arg(args, int);
		printf("index	=%d	result	=%d\n",i ,result);		

	}
	va_end(args);
}
*/

/*
void print_test(char *str, ...)
{
	size_t	i;
	int check;
	va_list abr;

	i = 0;
	va_start(abr,str);
	while (i < strlen(str))
	{
		if (str[i] == '.')
		{
			check = va_arg(abr, int);
			printf("%d", check);
		}
		else
			printf("%c", str[i]);
		i++;
	}
	va_end(abr);
}

void print_str(char *str, ...)
{
	va_list args;
	int		i;
	char	*result;

	printf("%s\n",str);	
	va_start(args, str);
	i = 0;
	while (i < 3)
	{
		result = va_arg(args, char*);
		printf("%s\n",result);
			i++;
	}

	va_end(args);
}
*/

/*
int		main(int argc, char** argv)
{
	int		len;
//	int		lenf;

	if (argc >= 2)
	{
		len = ft_printf(argv[1],'q');
		printf("\n");
		printf("len	=%d\n",len);

	}
	else
		printf("enter input\n");
	//print_int(10, 2, 3, "xcvb", 5);
	//print_str("aaaaa","bbbbbb","ccccccc`");

	//print_test("one two tree . five .", 4, 5);
	//int a = printf("123456\t789\n");
	//printf("%d\n",a);
	printf("**********************************************\n");
	return (0);
}
*/

int	main(void)
{
//	unsigned int	hex;
	unsigned int	dec;
	
	dec = 35631;
//	hex = ft_dectohex(dec);
	ft_printf("%x\n",dec);
	printf("%x\n",dec);
	
	return (0);
}

/*
int main(void)
{
	unsigned int	str = 160;
	int		len;
	len = ft_printf("ft_pntf	=%x where\n",str);
	printf("len	=%d\n",len);
	len = printf("default	=%x where\n", str);
	printf("len	=%d\n",len);
	printf("**********************************\n");
	return (0);
}
*/
