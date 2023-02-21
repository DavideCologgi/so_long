/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:27:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/21 12:17:37 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	vars;
	t_data	game;
	int		height;
	int		width;
	int		fd;

	fd = open("map1.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("file non valido");
		exit (1);
	}
	check_map(fd);
	vars.mlx = mlx_init();
	vars.win= mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");
	mlx_hook(vars.win, 2, 1L<<0, ESC_close, &vars);
	mlx_hook(vars.win, 17, 0, redx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
