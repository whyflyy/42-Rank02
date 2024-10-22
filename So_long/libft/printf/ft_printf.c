/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:46:27 by jcavadas          #+#    #+#             */
/*   Updated: 2024/06/25 13:36:10 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversions(const char c, va_list arglist)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arglist, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(arglist, unsigned long)));
	else if (c == 'd')
		return (ft_print_decimal(va_arg(arglist, int)));
	else if (c == 'i')
		return (ft_print_decimal(va_arg(arglist, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(arglist, int)));
	else if (c == 'x')
		return (ft_print_hexadecimal(va_arg(arglist, int), 'a'));
	else if (c == 'X')
		return (ft_print_hexadecimal(va_arg(arglist, int), 'A'));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (write(1, "0", 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	size_t	i;
	int		len;

	i = -1;
	len = 0;
	va_start(arglist, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += ft_conversions(str[++i], arglist);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
	}
	return (len);
}
/*
int	main(void)
{
	int		res = 0;
	char	c = 'x';
	char	str[] = "UwU OwO";
	int		n = 42;
	int		i = -123;
    int		*ptr = &i;
	
	res += ft_printf("AwA\n");
	res += ft_printf("Char: %c\n", c);
	res += ft_printf("String: %s\n", str);
    res += ft_printf("Pointer: %p\n", ptr);
	res += ft_printf("Decimal: %d\n", n);
	res += ft_printf("Int: %i\n", i);
	res += ft_printf("Unsigned: %u\n", n);
	res += ft_printf("Hexa lowercase: %x\n", n);
	res += ft_printf("Hexa uppercase: %X\n", i);
	res += ft_printf("Percent: %%\n");
	ft_printf("Res: %d\n", res);
	ft_printf("String: %s \t Hexa: %x \t Int: %i\n", str, n, i);
	return (0);
}*/
