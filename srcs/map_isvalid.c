/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:37:43 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:37:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_rectangle(t_game *game)
{
	size_t	first_line_len;
	size_t	row;

	first_line_len = ft_strlen(game->map[0]);
	row = 1;
	while (game->map[row])
	{
		if (ft_strlen(game->map[row]) != first_line_len)
			game_destroy(game, "Error:\nNot rectangular\n", 1, 2);
		row++;
	}
}

void	check_char(int row, int col, t_game *game)
{
	char	ch;

	ch = game->map[row][col];
	if (ch == '1' || ch == '0')
		return ;
	else if (ch == 'P')
	{
		game->player_count++;
		game->player_x = col;
		game->player_y = row;
	}
	else if (ch == 'E')
	{
		game->exit_count++;
		game->exit_x = col;
		game->exit_y = row;
	}
	else if (ch == 'C')
		game->collectable_count++;
	else
		game_destroy(game, "Error:\nInvalid characters in the map\n", 1, 2);
}

void	is_valid_char(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			check_char(row, col, game);
			col++;
		}
		row++;
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| game->collectable_count <= 0)
		game_destroy(game, "Error:\nInvalid count of characters\n", 1, 2);
}

void	is_surrounded(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			game_destroy(game,
				"Error:\nThe map is not surrounded by walls\n", 1, 2);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			game_destroy(game,
				"Error:\nThe map is not surrounded by walls\n", 1, 2);
		i++;
	}
}
