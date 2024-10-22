/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 00:45:53 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/25 12:39:09 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_map_rows(char *map_name, t_game *game)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", game);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (rows);
}

int	ft_count_map_width(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] != '\n' && row[i] != '\r')
		i++;
	return (i);
}

void	fill_map(int fd, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
}

void	get_map(char *map_name, t_game *game)
{
	char	*line;
	int		fd;

	game->height = ft_count_map_rows(map_name, game);
	if (game->height <= 0)
		error_msg("Empty map!", game);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", game);
	game->map = ft_calloc(sizeof(char *), (game->height));
	if (!game->map)
		return ;
	fill_map(fd, game);
	game->width = ft_count_map_width(game->map[0]);
	close(fd);
}

void	char_check(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->width > x)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
			&& game->map[y][x] != 'E' && game->map[y][x] != 'P'
			&& game->map[y][x] != 'C' && game->map[y][x] != '\n'
			&& game->map[y][x] != '\0')
				error_msg("There is an invalid character in the map!", game);
			x++;
		}
		y++;
	}
}
