/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:35:23 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:35:25 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_images_2(t_game *game)
{
	int	width;
	int	height;

	game->player = mlx_xpm_file_to_image(game->mlx, "./imgs/player.xpm",
			&width, &height);
	if (!game->player)
		game_destroy(game, "Error:\nFailed to load Player!\n", 1, 2);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm",
			&width, &height);
	if (!game->wall)
		game_destroy(game, "Error:\nFailed to load Walls!\n", 1, 2);
	game->player_exit = mlx_xpm_file_to_image(game->mlx,
			"./imgs/player_exit.xpm", &width, &height);
	if (!game->player_exit)
		game_destroy(game, "Error:\nFailed to load Player exit!\n", 1, 2);
	game->exit1 = mlx_xpm_file_to_image(game->mlx, "./imgs/exit1.xpm",
			&width, &height);
	if (!game->exit1)
		game_destroy(game, "Error:\nFailed to load Exit1!\n", 1, 2);
}

void	fill_images(t_game *game)
{
	int	width;
	int	height;

	game->background = mlx_xpm_file_to_image(game->mlx, "./imgs/background.xpm",
			&width, &height);
	if (!game->background)
		game_destroy(game, "Error:\nFailed to load background!\n", 1, 2);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm",
			&width, &height);
	if (!game->exit)
		game_destroy(game, "Error:\nFailed to load Exit!\n", 1, 2);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"./imgs/collectable.xpm", &width, &height);
	if (!game->collectable)
		game_destroy(game,
			"Error:\nFailed to load Collectables!\n", 1, 2);
	fill_images_2(game);
}

void	put_image(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall, col * 40, row * 40);
	if (game->map[row][col] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->background, col * 40, row * 40);
	if (game->map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectable, col * 40, row * 40);
	if (game->map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit1, col * 40, row * 40);
	if (game->map[row][col] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player, col * 40, row * 40);
}

void	draw_game(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			put_image(game, row, col);
			col++;
		}
		row++;
	}
}

void	draw(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->width * 40,
			game->height * 40, "Fyodor and apples");
	if (!game->window)
		game_destroy(game, "Error:\nWindow failed", 1, 2);
	fill_images(game);
	draw_game(game);
	mlx_hook(game->window, 2, 1L << 0, key_hook, game);
	mlx_hook(game->window, 17, 0, destroy_key, game);
	mlx_loop(game->mlx);
}
