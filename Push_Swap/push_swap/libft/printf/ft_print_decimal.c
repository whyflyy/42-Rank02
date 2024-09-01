/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:48:37 by jcavadas          #+#    #+#             */
/*   Updated: 2023/10/28 10:21:22 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	char	*temp;
	size_t	len;

	if (!n)
		return (write(1, "0", 1));
	temp = ft_itoa(n);
	ft_putstr_fd(temp, 1);
	len = ft_strlen(temp);
	free(temp);
	return (len);
}
