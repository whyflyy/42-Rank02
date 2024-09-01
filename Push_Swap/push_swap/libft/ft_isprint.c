/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:36:24 by jcavadas          #+#    #+#             */
/*   Updated: 2023/10/06 12:38:08 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main(void)
{
	ft_putnbr_fd(ft_isprint(2), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isprint(69), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isprint(45), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isprint(127), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
