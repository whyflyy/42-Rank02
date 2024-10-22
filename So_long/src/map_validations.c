/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:46:21 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/18 14:45:55 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (ft_count_map_width(game->map[i]) != game->width)
			error_msg("Map isn't rectangular!", game);
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	y;
	int	x;

	x = game->width - 1;
	y = 0;
	while (game->height > y)
	{
		if (game->map[y][0] != '1')
			error_msg("The left side of the map isn't all 1's!", game);
		if (game->map[y][x] != '1')
			error_msg("The right side eof the map isn't all 1's!", game);
		y++;
	}
	x = 0;
	y = game->height - 1;
	while (game->width > x)
	{
		if (game->map[0][x] != '1')
			error_msg("The top side of the map isn't all 1's!", game);
		if (game->map[y][x] != '1')
			error_msg("The bottom side of the map isn't all 1's!", game);
		x++;
	}
}

void	player_check(t_game *game)
{
	int	y;
	int	x;
	int	p_count;

	p_count = 0;
	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->width > x)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_position.x = x;
				game->player_position.y = y;
				p_count++;
			}
			x++;
		}
		y++;
	}
	if (p_count != 1)
		error_msg("Error with the player starting position!", game);
}

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;
	int	e_count;

	y = 0;
	e_count = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->width > x)
		{
			if (game->map[y][x] == 'C')
				game->collectible_count++;
			if (game->map[y][x] == 'E')
				e_count++;
			x++;
		}
		y++;
	}
	if (e_count != 1)
		error_msg("Error with the exit!", game);
	if (game->collectible_count < 1)
		error_msg("There aren't enough collectibles!", game);
}

void	ft_map_check(t_game *game)
{
	is_rectangle(game);
	check_walls(game);
	char_check(game);
	player_check(game);
	count_collectibles(game);
	check_path(game);
}
