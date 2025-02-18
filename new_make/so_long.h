/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:41:15 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:41:17 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
typedef struct game
{
	char	**map;
	char	**copy_map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		player_count;
	int		collectable_count;
	int		exit_count;
	int		exit_x;
	int		exit_y;
	void	*mlx;
	void	*window;
	void	*background;
	void	*player;
	void	*wall;
	void	*exit;
	void	*collectable;
	int		movements_count;
	void	*player_exit;
	void	*exit1;
}	t_game;


int		key_hook(int keycode, t_game *game);
void	print_move(t_game *game);
void	game_init(t_game *game);
void	copy_map_init(t_game *game);
void	map_init(t_game *game, char *file_name);
void	height_width_init(t_game *game, char *file_name);
int		game_destroy(t_game *game, char *message, int exit_signal, int fd);
void	die(int exit_signal, char *error_message);
void	ft_exit_file(int exit_signal, char *error_message, int fd);
void	err_free(t_game *game, char *message, int exit_signal, int fd);
void	*ft_free_matrix(char **map);
void	check_copy_char(int i, int j, t_game *game);
void	check_path(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	is_surrounded(t_game *game);
void	is_valid_char(t_game *game);
void	check_char(int i, int j, t_game *game);
void	is_rectangle(t_game *game);
void	is_dot_ber(char *file_path);
void	draw(t_game *game);
void	draw_game(t_game *game);
void	put_image(t_game *game, int i, int j);
void	fill_images(t_game *game);
void	fill_images_2(t_game *game);
void	move(t_game *game, int x, int y);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
int		destroy_key(t_game *game);

#endif
