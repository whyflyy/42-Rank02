/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:54:08 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/25 12:40:22 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg, t_game *game)
{
	ft_printf("Error! %s\n", msg);
	ft_quit_game(game);
	exit(0);
}

static bool	check_type(char *str, char *extension)
{
	size_t	len;
	size_t	ext_len;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(str);
	ext_len = ft_strlen(extension);
	j = ext_len;
	while (i++ <= ext_len)
	{
		if (str[len--] != extension[j--])
			return (false);
	}
	return (true);
}

void	check_params(int argc, char **argv)
{
	int		fd;
	size_t	bytes_read;

	if (argc != 2)
		error_msg("Invalid number of arguments", NULL);
	if (!(check_type(argv[1], ".ber")))
		error_msg("Wrong file type! File must be .ber", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", NULL);
	close(fd);
}
