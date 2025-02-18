/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:35:23 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:35:25 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_free_matrix(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	err_free(t_game *game, char *message, int exit_signal, int fd)
{
	if (game)
	{
		if (game->map)
			game->map = ft_free_matrix(game->map);
		if (game->copy_map)
			game->copy_map = ft_free_matrix(game->copy_map);
	}
	ft_putstr_fd(message, fd);
	exit(exit_signal);
}

void	ft_exit_file(int exit_signal, char *error_message, int fd)
{
	ft_putstr_fd(error_message, 2);
	close(fd);
	exit(exit_signal);
}

int	game_destroy(t_game *game, char *message, int exit_signal, int fd)
{
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->collectable)
		mlx_destroy_image(game->mlx, game->collectable);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player_exit)
		mlx_destroy_image(game->mlx, game->player_exit);
	if (game->exit1)
		mlx_destroy_image(game->mlx, game->exit1);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	err_free(game, message, exit_signal, fd);
	return (0);
}
