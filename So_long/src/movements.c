/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:31:19 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/18 15:08:14 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(t_game *game)
{
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[game->player_position.y][game->player_position.x] == 'E'
		&& game->collected == game->collectible_count)
	{
		ft_printf("Congratulations! You have escaped the ancient maze! \n");
		ft_quit_game(game);
	}
	else if (game->map[game->player_position.y][game->player_position.x] == 'C')
	{
		game->map[game->player_position.y][game->player_position.x] = '0';
		game->collected++;
		if (game->collected == game->collectible_count)
		{
			light_portal(game);
			game->portal_lit = true;
		}
	}
}

void	move_up(t_game *game)
{
	int	old_y;
	int	new_y;

	old_y = game->player_position.y;
	new_y = game->player_position.y - 1;
	game->player_position.y = new_y;
	game->moves++;
	if (game->map[new_y][game->player_position.x] == 'E'
		&& game->portal_lit == false)
		put_texture(game, "./textures/Portal_unlit_pu.xpm",
			new_y * SIZE, game->player_position.x * SIZE);
	else if (game->map[new_y][game->player_position.x] == 'E'
		&& game->portal_lit == true)
		put_texture(game, "./textures/Portal_lit_pu.xpm",
			new_y * SIZE, game->player_position.x * SIZE);
	else
		put_texture(game, "./textures/Player_up.xpm",
			new_y * SIZE, game->player_position.x * SIZE);
	checker(game);
	if (game->map[old_y][game->player_position.x] == 'E')
		put_texture(game, "./textures/Portal_unlit.xpm",
			old_y * SIZE, game->player_position.x * SIZE);
	else
		put_texture(game, "./textures/Grass.xpm",
			old_y * SIZE, game->player_position.x * SIZE);
}

void	move_down(t_game *game)
{
	int	old_y;
	int	new_y;

	old_y = game->player_position.y;
	new_y = game->player_position.y + 1;
	game->player_position.y = new_y;
	game->moves++;
	if (game->map[new_y][game->player_position.x] == 'E'
		&& game->portal_lit == false)
		put_texture(game, "./textures/Portal_unlit_pd.xpm",
			new_y * SIZE, game->player_position.x * SIZE);
	else if (game->map[new_y][game->player_position.x] == 'E'
		&& game->portal_lit == true)
		put_texture(game, "./textures/Portal_lit_pd.xpm",
			new_y * SIZE, game->player_position.x * SIZE);
	else
		put_texture(game, "./textures/Player_down.xpm",
			new_y * SIZE, game->player_position.x * SIZE);
	checker(game);
	if (game->map[old_y][game->player_position.x] == 'E')
		put_texture(game, "./textures/Portal_unlit.xpm",
			old_y * SIZE, game->player_position.x * SIZE);
	else
		put_texture(game, "./textures/Grass.xpm",
			old_y * SIZE, game->player_position.x * SIZE);
}

void	move_left(t_game *game)
{
	int	old_x;
	int	new_x;

	old_x = game->player_position.x;
	new_x = game->player_position.x - 1;
	game->player_position.x = new_x;
	game->moves++;
	if (game->map[game->player_position.y][new_x] == 'E'
		&& game->portal_lit == false)
		put_texture(game, "./textures/Portal_unlit_pl.xpm",
			game->player_position.y * SIZE, new_x * SIZE);
	else if (game->map[game->player_position.y][new_x] == 'E'
		&& game->portal_lit == true)
		put_texture(game, "./textures/Portal_lit_pl.xpm",
			game->player_position.y * SIZE, new_x * SIZE);
	else
		put_texture(game, "./textures/Player_left.xpm",
			game->player_position.y * SIZE, new_x * SIZE);
	checker(game);
	if (game->map[game->player_position.y][old_x] == 'E')
		put_texture(game, "./textures/Portal_unlit.xpm",
			game->player_position.y * SIZE, old_x * SIZE);
	else
		put_texture(game, "./textures/Grass.xpm",
			game->player_position.y * SIZE, old_x * SIZE);
}

void	move_right(t_game *game)
{
	int	old_x;
	int	new_x;

	old_x = game->player_position.x;
	new_x = game->player_position.x + 1;
	game->player_position.x = new_x;
	game->moves++;
	if (game->map[game->player_position.y][new_x] == 'E'
		&& game->portal_lit == false)
		put_texture(game, "./textures/Portal_unlit_pr.xpm",
			game->player_position.y * SIZE, new_x * SIZE);
	else if (game->map[game->player_position.y][new_x] == 'E'
		&& game->portal_lit == true)
		put_texture(game, "./textures/Portal_lit_pr.xpm",
			game->player_position.y * SIZE, new_x * SIZE);
	else
		put_texture(game, "./textures/Player_right.xpm",
			game->player_position.y * SIZE, new_x * SIZE);
	checker(game);
	if (game->map[game->player_position.y][old_x] == 'E')
		put_texture(game, "./textures/Portal_unlit.xpm",
			game->player_position.y * SIZE, old_x * SIZE);
	else
		put_texture(game, "./textures/Grass.xpm",
			game->player_position.y * SIZE, old_x * SIZE);
}
