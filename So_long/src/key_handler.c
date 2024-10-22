/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:41:47 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/18 14:51:34 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	can_move(t_game *game, char *dir, int y, int x)
{
	if (ft_strncmp(dir, "up", 2) == 0)
	{
		if (game->map[y - 1][x] == '1')
			return ;
		move_up(game);
	}
	else if (ft_strncmp(dir, "down", 4) == 0)
	{
		if (game->map[y + 1][x] == '1')
			return ;
		move_down(game);
	}
	else if (ft_strncmp(dir, "left", 4) == 0)
	{
		if (game->map[y][x - 1] == '1')
			return ;
		move_left(game);
	}
	else if (ft_strncmp(dir, "right", 5) == 0)
	{
		if (game->map[y][x + 1] == '1')
			return ;
		move_right(game);
	}
}

int	key_handler(int key, t_game *game)
{
	int	y;
	int	x;

	y = game->player_position.y;
	x = game->player_position.x;
	if (key == XK_Escape)
	{
		ft_printf("ESC has been pressed, exiting game\n");
		ft_quit_game(game);
	}
	if (key == 'w' || key == XK_Up)
		can_move(game, "up", y, x);
	if (key == 's' || key == XK_Down)
		can_move(game, "down", y, x);
	if (key == 'a' || key == XK_Left)
		can_move(game, "left", y, x);
	if (key == 'd' || key == XK_Right)
		can_move(game, "right", y, x);
	return (0);
}

void	light_portal(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
				put_texture(game, "./textures/Portal_lit.xpm",
					y * SIZE, x * SIZE);
			x++;
		}
		y++;
	}
}
