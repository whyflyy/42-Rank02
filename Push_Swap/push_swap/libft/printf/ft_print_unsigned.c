/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:32:24 by jcavadas          #+#    #+#             */
/*   Updated: 2023/10/28 16:49:41 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_countdig(unsigned int n)
{
	unsigned int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa_long(unsigned int n)
{
	char			*res;
	unsigned int	dig;
	unsigned int	num;

	num = n;
	dig = ft_countdig(num);
	res = (char *)malloc(sizeof(char) * (dig + 1));
	if (!res)
		return (NULL);
	res[dig--] = '\0';
	if (num == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (num > 0)
	{
		res[dig--] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*temp;
	size_t	len;

	if (!n)
		return (write(1, "0", 1));
	temp = ft_itoa_long(n);
	ft_putstr_fd(temp, 1);
	len = ft_strlen(temp);
	free(temp);
	return (len);
}
