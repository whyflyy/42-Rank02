/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:39 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/25 14:19:04 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->map_name = NULL;
	game->moves = 0;
	game->width = 0;
	game->height = 0;
	game->collectible_count = 0;
	game->can_collect = 0;
	game->collected = 0;
	game->can_exit = 0;
	game->coordinates.x = 0;
	game->coordinates.y = 0;
	game->img_size.y = 0;
	game->img_size.x = 0;
	game->portal_lit = false;
}

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
	game->img_size.y = SIZE;
	game->img_size.x = SIZE;
}

t_game	*init(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	init_window(game);
	return (game);
}
