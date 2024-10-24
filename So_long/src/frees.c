/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:04:58 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/11 15:06:07 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit_game(t_game *game)
{
	get_next_line(-1);
	free_all(game);
	exit (0);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map);
		return ;
	}
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
}

void	free_map_copy(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map_copy);
		return ;
	}
	while (++i < game->height)
		free(game->map_copy[i]);
	free(game->map_copy);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game);
	if (game->map_copy)
		free_map_copy(game->map_copy, game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free (game);
}
