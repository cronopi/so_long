/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:20:26 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/04 13:58:46 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_double_pointer(t_patata *init)
{
	int	i;

	i = 0;
	while (init->img.map[i] != NULL)
	{
		free(init->img.map[i]);
		i++;
	}
	free(init->img.map);
}

void	close_program(t_patata *init)
{
	mlx_destroy_image(init->mlx, init->img.pacman[0]);
	mlx_destroy_image(init->mlx, init->img.pacman[1]);
	mlx_destroy_image(init->mlx, init->img.pacman[2]);
	mlx_destroy_image(init->mlx, init->img.pacman[3]);
	mlx_destroy_image(init->mlx, init->img.exit_portal);
	mlx_destroy_image(init->mlx, init->img.wall);
	mlx_destroy_image(init->mlx, init->img.colectables);
	free_double_pointer(init);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
}

int	close_window(t_patata *init)
{
	mlx_destroy_window(init->mlx, init->win);
	close_program(init);
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_coordinates	map_size;
	t_patata		init;

	init.mlx = mlx_init();
	if (init.mlx == NULL)
		return (1);
	(void)map_size;
	(void)argc;
	(void)argv;
	init.img.map = open_map(argc, argv, &init);
	map_size = map_lengh_high(init.img.map);
	init.win = mlx_new_window(init.mlx, (map_size.x * 32)
			+ 64, (map_size.y * 32) + 64, "so_long");
	if (init.win == NULL)
	{
		free_double_pointer(&init);
		return (1);
	}
	set_up(&init);
	mlx_hook(init.win, 2, 1L << 0, key_hook, &init);
	mlx_hook(init.win, 17, 1L << 17, close_window, &init);
	ft_funtion(&init);
	mlx_loop(init.mlx);
	//close_window(&init); // solo para comprobar leaks
	close_program(&init);
	return (0);
}
