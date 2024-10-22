/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:38:18 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/17 15:15:53 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_game *game, char *texture, int y, int x)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, texture,
			&game->img_size.x, &game->img_size.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.mlx_img, x, y);
}

void	render_walls(t_game *game, int y, int x, char pos)
{
	if (y == 0 && x == 0)
		put_texture(game, "./textures/TL_corner.xpm", y * SIZE, x * SIZE);
	else if (y == game->height - 1 && x == 0)
		put_texture(game, "./textures/BL_corner.xpm", y * SIZE, x * SIZE);
	else if (y == 0 && x == game->width - 1)
		put_texture(game, "./textures/TR_corner.xpm", y * SIZE, x * SIZE);
	else if (y == game->height - 1 && x == game->width - 1)
		put_texture(game, "./textures/BR_corner.xpm", y * SIZE, x * SIZE);
	else if (y == 0)
		put_texture(game, "./textures/Top_wall.xpm", y * SIZE, x * SIZE);
	else if (y == game->height - 1)
		put_texture(game, "./textures/Bottom_wall.xpm", y * SIZE, x * SIZE);
	else if (x == 0)
		put_texture(game, "./textures/Left_wall.xpm", y * SIZE, x * SIZE);
	else if (x == game->width - 1)
		put_texture(game, "./textures/Right_wall.xpm", y * SIZE, x * SIZE);
	else
		put_texture(game, "./textures/Wall.xpm", y * SIZE, x * SIZE);
}

void	render_textures(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map[y][x];
	if (pos == '1')
		render_walls(game, y, x, pos);
	else if (pos == 'E')
		put_texture(game, "./textures/Portal_unlit.xpm", y * SIZE, x * SIZE);
	else if (pos == 'P')
		put_texture(game, "./textures/Player_down.xpm", y * SIZE, x * SIZE);
	else if (pos == 'C')
		put_texture(game, "./textures/Scroll.xpm", y * SIZE, x * SIZE);
	else if (pos == '0')
		put_texture(game, "./textures/Grass.xpm", y * SIZE, x * SIZE);
}

void	render_map(t_game *game)
{
	game->coordinates.y = 0;
	while (game->coordinates.y < game->height)
	{
		game->coordinates.x = 0;
		while (game->coordinates.x < game->width)
		{
			render_textures(game, game->coordinates.y, game->coordinates.x);
			game->coordinates.x++;
		}
		game->coordinates.y++;
	}
}

void	display_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
		error_msg("Error with the mlx_ptr!", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * SIZE,
			game->height * SIZE, "so_long");
	if (game->win_ptr == NULL)
		error_msg("Error with the win_ptr!", game);
	render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &key_handler, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_quit_game, game);
	mlx_loop(game->mlx_ptr);
}
