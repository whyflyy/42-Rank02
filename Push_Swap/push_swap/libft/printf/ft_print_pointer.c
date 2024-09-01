/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:40:01 by jcavadas          #+#    #+#             */
/*   Updated: 2023/11/01 11:19:04 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_print_hexa(unsigned long n)
{
	if (n >= 16)
	{
		ft_print_hexa(n / 16);
		ft_print_hexa(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n + 'a' - 10), 1);
	}
}

int	ft_print_pointer(unsigned long n)
{
	if (!n)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	ft_print_hexa(n);
	return (ft_hexa_len(n) + 2);
}
