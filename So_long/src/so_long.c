/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:13:42 by jcavadas          #+#    #+#             */
/*   Updated: 2024/10/18 20:09:55 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	char	*line;
	int		fd;
	t_game	*game;

	check_params(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("File not found!", NULL);
	game = init();
	game->map_name = argv[1];
	get_map(argv[1], game);
	ft_map_check(game);
	display_window(game);
	close(fd);
	ft_quit_game(game);
	return (1);
}
