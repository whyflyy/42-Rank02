/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:45:02 by jcavadas          #+#    #+#             */
/*   Updated: 2024/07/05 16:28:26 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_size(int pid, int size)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (size & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	send_message(int pid, char *str, int size)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < size)
	{
		x = 8;
		while (x > 0)
		{
			if (str[i] & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			str[i] = str[i] << 1;
			x--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		len;
	int		pid;

	if (argc != 3)
	{
		ft_printf("Incorrect usage! It should be: ./client <PID> <Message>\n");
		return (0);
	}
	len = 0;
	str = argv[2];
	len = ft_strlen(str);
	pid = ft_atoi(argv[1]);
	send_size(pid, len);
	send_message(pid, str, len);
	return (0);
}
