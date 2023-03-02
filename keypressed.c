/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:54:07 by dcologgi          #+#    #+#             */
/*   Updated: 2024/02/28 09:54:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_touch(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos] == 'N')
	{
		printf("%s\n", "YOU LOSE");
		exit_game(game);
	}
}

void	grab_collectible(t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos] == 'C')
		game->collectible--;
	return ;
}

void	pg_move(t_data *game, int key_pressed)
{
	if (key_pressed == 14 && game->map[game->pgr_pos - 1][game->pgc_pos] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgr_pos--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
	if (key_pressed == 1 && game->map[game->pgr_pos + 1][game->pgc_pos] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgr_pos++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
	if (key_pressed == 0 && game->map[game->pgr_pos][game->pgc_pos - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgc_pos--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
	if (key_pressed == 2 && game->map[game->pgr_pos][game->pgc_pos + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->pgc_pos++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->pgc_pos * 64, game->pgr_pos * 64);
		game->move_counter++;
	}
	grab_collectible(game);
	enemy_touch(game);
	printf("%i\n", game->move_counter);
	return ;
}

int	keypressed(int key_pressed, t_data *game)
{
	if (game->map[game->pgr_pos][game->pgc_pos] == 'E'
		&& game->collectible == 0)
	{
		printf("%s\n", "YOU WIN");
		exit_game(game);
	}
	pg_move(game, key_pressed);
	return (1);
}
