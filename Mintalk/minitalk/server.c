/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:45:07 by jcavadas          #+#    #+#             */
/*   Updated: 2024/07/05 11:53:02 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_size = 0;

char	*ft_printffree(char *str)
{
	str[g_size] = '\0';
	ft_printf("Message: %s\n", str);
	free (str);
	g_size = 0;
	return (NULL);
}

char	*ft_create(int size)
{
	char	*str;

	str = NULL;
	str = ft_calloc((g_size + 1), sizeof(char));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	return (str);
}

void	handler_size(int sig)
{
	static int	size = 0;
	static int	bitcount = 0;

	if (sig == SIGUSR2)
		size = size << 1;
	else
		size = (size << 1) | 1;
	bitcount++;
	if (bitcount == 32)
	{
		g_size = size;
		ft_printf("Received size: %i\n", g_size);
		bitcount = 0;
		size = 0;
	}
}

void	handler_message(int sig)
{
	static int	j = 0;
	static char	c = 0;
	static int	i = 0;
	static char	*str = NULL;

	if (sig == SIGUSR2)
		c = c << 1;
	else
		c = (c << 1) | 1;
	i++;
	if (i == 8)
	{
		if (str == NULL)
			str = ft_create(g_size);
		str[j] = c;
		j++;
		i = 0;
		c = 0;
	}
	if (j == g_size)
	{
		j = 0;
		str = ft_printffree(str);
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		if (g_size == 0)
		{
			signal(SIGUSR1, handler_size);
			signal(SIGUSR2, handler_size);
		}
		else
		{
			signal(SIGUSR1, handler_message);
			signal(SIGUSR2, handler_message);
		}
	}
}
