/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:39:04 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:39:06 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_dot_ber(char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (len < 4 || ft_strncmp(file_path + (len - 4), ".ber", 4) != 0)
		die(1, "Error:\nWrong file Extention!\n");
}

void	print_move(t_game *game)
{
	ft_printf("movements count: %d.\n", game->movements_count);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game_destroy(game, "Game Exit!\n", 0, 1);
	if (keycode == 97 || keycode == 65361)
		move_left(game);
	if (keycode == 119 || keycode == 65362)
		move_up(game);
	if (keycode == 100 || keycode == 65363)
		move_right(game);
	if (keycode == 115 || keycode == 65364)
		move_down(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		die(1, "Error:\nInvalid arguments!\n");
	is_dot_ber(argv[1]);
	game_init(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		err_free(&game, "Error:\nmlx_init() faild!\n", 1, 2);
	height_width_init(&game, argv[1]);
	map_init(&game, argv[1]);
	is_rectangle(&game);
	is_valid_char(&game);
	is_surrounded(&game);
	flood_fill(&game, game.player_x, game.player_y);
	check_path(&game);
	draw(&game);
	free(game.mlx);
	err_free(&game, "", 0, 1);
	return (0);
}
