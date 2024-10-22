/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:30:13 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/25 12:34:27 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

# define SIZE 64

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	char	*map_name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

	t_point	player_position;
	t_point	coordinates;
	t_point	img_size;

	int		moves;
	int		height; //rows - y
	int		width; //collumns - x
	int		collectible_count; //collect
	int		collected; //coin_bag
	int		can_collect; //collect_check
	int		can_exit; //exit_check
	bool	portal_lit;
}			t_game;

void	error_msg(char *msg, t_game *game);
void	check_params(int argc, char **argv);
void	get_map(char *map_name, t_game *game);

//map_utils
int		ft_count_map_rows(char *map_name, t_game *game);
int		ft_count_map_width(char *row);
void	fill_map(int fd, t_game *game);
void	char_check(t_game *game);

//init
void	init_window(t_game *game);
void	init_game(t_game *game);
t_game	*init(void);

//frees
int		ft_quit_game(t_game *game);
void	free_map(char **map, t_game *game);
void	free_map_copy(char **map, t_game *game);
void	free_all(t_game *game);

//Map validations
void	ft_map_check(t_game *game);

//Path check
void	check_path(t_game *game);

//Init display
void	display_window(t_game *game);
void	put_texture(t_game *game, char *texture, int y, int x);

//Key Handler
int		key_handler(int key, t_game *game);
void	light_portal(t_game *game);

//Movements
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
