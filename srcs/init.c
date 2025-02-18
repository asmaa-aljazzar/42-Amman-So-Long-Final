/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:37:37 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:37:39 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map = NULL;
	game->copy_map = NULL;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player = NULL;
	game->player_count = 0;
	game->collectable_count = 0;
	game->exit_count = 0;
	game->exit = NULL;
	game->exit_x = 0;
	game->exit_y = 0;
	game->background = NULL;
	game->collectable = NULL;
	game->wall = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->movements_count = 0;
}

void	copy_map_init(t_game *game)
{
	int		row;
	int		width;
	int		height;

	width = 0;
	height = 0;
	row = 0;
	game->copy_map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->copy_map)
		err_free(game, "Error:\ncopy_map: Malloc failed!\n", 1, 2);
	while (row < game->height)
	{
		game->copy_map[row] = ft_strdup(game->map[row]);
		if (!game->copy_map[row])
			err_free(game, "Error:\ncopy_map[row]: Malloc failed!", 1, 2);
		row++;
	}
	mlx_get_screen_size(game->mlx, &width, &height);
	if (game->width * 40 > width || game->height * 40 > height)
		game_destroy(game, "Error:\nMap is too big!\n", 1, 2);
	game->copy_map[row] = NULL;
}

void	map_init(t_game *game, char *file_name)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		die(1, "Error:\nFailed to open file!\n");
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		ft_exit_file(1, "Error:\nmap_init(): Malloc failed!\n", fd);
	row = 0;
	line = get_next_line(fd);
	while (line && row < game->height)
	{
		game->map[row] = line;
		row++;
		line = get_next_line(fd);
	}
	game->map[row] = NULL;
	copy_map_init(game);
	close(fd);
}

void	height_width_init(t_game *game, char *file_name)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		game_destroy(game, "Error:\nFailed to open file!\n", 1, 2);
	line = get_next_line(fd);
	if (!line)
		game_destroy(game, "Error:\nEmpty map!\n", 1, 2);
	game->width = ft_strlen(line) - 1;
	row = 0;
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	game->height = row;
	close(fd);
}

int	destroy_key(t_game *game)
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
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	err_free(game, "Game Exit!\n", 0, 1);
	return (0);
}
