/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:04:15 by jcavadas          #+#    #+#             */
/*   Updated: 2023/11/01 11:20:42 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned int n)
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

static void	ft_print_hexa(unsigned int n, char uporlow)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	else if (n >= 16)
	{
		ft_print_hexa(n / 16, uporlow);
		ft_print_hexa(n % 16, uporlow);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n + uporlow - 10), 1);
	}
}

int	ft_print_hexadecimal(unsigned int n, char uporlow)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		ft_print_hexa(n, uporlow);
		return (ft_hexa_len(n));
	}
}
