/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:36:55 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_copy_char(int i, int j, t_game *game)
{
	char	ch;

	ch = game->copy_map[i][j];
	if (ch == '1' || ch == '0' || ch == 'V')
		return ;
	else
		game_destroy(game, "Error:\nInvalid player-exit path\n", 1, 2);
}

void	check_path(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			check_copy_char(row, col, game);
			col++;
		}
		row++;
	}
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->copy_map[y][x] == '1')
		return ;
	else if (game->copy_map[y][x] == 'V')
		return ;
	game->copy_map[y][x] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y - 1);
}
