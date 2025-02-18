/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:36:55 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move(t_game *game, int x, int y)
{
	game->movements_count++;
	mlx_put_image_to_window(game->mlx, game->window,
		game->background, game->player_x * 40, game->player_y * 40);
	game->player_x += x;
	game->player_y += y;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player, game->player_x * 40, game->player_y * 40);
	if (!(game->player_x == game->exit_x && game->player_y == game->exit_y)
		&& game->collectable_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit, game->exit_x * 40, game->exit_y * 40);
	}
	else if (!(game->player_x == game->exit_x
			&& game->player_y == game->exit_y))
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit1, game->exit_x * 40, game->exit_y * 40);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_exit, game->exit_x * 40, game->exit_y * 40);
	}
	print_move(game);
}

void	move_left(t_game *game)
{
	if (game->player_x - 1 > 0
		&& game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& 0 == game->collectable_count)
		{
			game->movements_count++;
			print_move(game);
			game_destroy(game, "Thank you for playing!\n", 0, 1);
		}
		else
		{
			if (game->map[game->player_y][game->player_x - 1] == 'C')
			{
				game->collectable_count--;
				game->map[game->player_y][game->player_x - 1] = '0';
			}
			move(game, -1, 0);
		}
	}
}

void	move_up(t_game *game)
{
	if (game->player_y - 1 >= 0
		&& game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& 0 == game->collectable_count)
		{
			game->movements_count++;
			print_move(game);
			game_destroy(game, "Thank you for playing!\n", 0, 1);
		}
		else
		{
			if (game->map[game->player_y - 1][game->player_x] == 'C')
			{
				game->collectable_count--;
				game->map[game->player_y - 1][game->player_x] = '0';
			}
			move(game, 0, -1);
		}
	}
}

void	move_right(t_game *game)
{
	if (game->player_x + 1 < game->width
		&& game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& 0 == game->collectable_count)
		{
			game->movements_count++;
			print_move(game);
			game_destroy(game, "Thank you for Playing!\n", 0, 1);
		}
		else
		{
			if (game->map[game->player_y][game->player_x + 1] == 'C')
			{
				game->collectable_count--;
				game->map[game->player_y][game->player_x + 1] = '0';
			}
			move(game, 1, 0);
		}
	}
}

void	move_down(t_game *game)
{
	if (game->player_y + 1 < game->height
		&& game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& 0 == game->collectable_count)
		{
			game->movements_count++;
			print_move(game);
			game_destroy(game, "Thank you for playing!\n", 0, 1);
		}
		else
		{
			if (game->map[game->player_y + 1][game->player_x] == 'C')
			{
				game->collectable_count--;
				game->map[game->player_y + 1][game->player_x] = '0';
			}
			move(game, 0, 1);
		}
	}
}
