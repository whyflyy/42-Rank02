/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:18:34 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/25 12:39:18 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game, char *map_name)
{
	int	fd;
	int	i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", game);
	game->map_copy = ft_calloc(sizeof(char *), (game->height));
	if (!game->map_copy)
		return ;
	i = 0;
	while (i < game->height)
	{
		game->map_copy[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	flood_fill(char **map_copy, int y, int x, t_game *game)
{
	if (y < 0 || x < 0 || y >= game->height || x >= game->width)
		return (0);
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return (0);
	if (map_copy[y][x] == 'C')
		game->can_collect++;
	if (map_copy[y][x] == 'E')
		game->can_exit++;
	if (map_copy[y][x] != '1')
		map_copy[y][x] = 'F';
	flood_fill(map_copy, y, x - 1, game);
	flood_fill(map_copy, y, x + 1, game);
	flood_fill(map_copy, y - 1, x, game);
	flood_fill(map_copy, y + 1, x, game);
	return (0);
}

void	check_path(t_game *game)
{
	copy_map(game, game->map_name);
	flood_fill(game->map_copy, game->player_position.y,
		game->player_position.x, game);
	if (game->can_exit != 1)
		error_msg("The player can't reach the exit!", game);
	if (game->can_collect != game->collectible_count)
		error_msg("The player can't reach all collectibles!", game);
}
