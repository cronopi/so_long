/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:40:55 by rcastano          #+#    #+#             */
/*   Updated: 2023/06/21 14:56:104 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_so_long.h"

void	free_double_pointer(t_patata *init)
{
	int	i;

	i = 0;
	while(init->img.map[i] != NULL)
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
}

int	close_window(t_patata *init)
{
	mlx_destroy_window(init->mlx, init->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_coordinates	map_size;
	t_patata		init;

	init.mlx = mlx_init();
	if (init.mlx == NULL)
		return (1);
	init.img.map = open_map(argc, argv);
	map_size = map_lengh_high(init.img.map);
	init.win = mlx_new_window(init.mlx, (map_size.x * 32) + 64, (map_size.y * 32) + 64, "so_long");
	if (init.win == NULL)
	{
		free_double_pointer(&init);
		return (1);
	}
	set_up(&init);
	mlx_hook(init.win, 2, 1L<<0, key_hook, &init);
	mlx_hook(init.win, 17, 1L<<17, close_window, &init);
	ft_funtion(&init);
	mlx_loop(init.mlx);
	close_program(&init);
	//free_double_pointer(&init);
	return (0);
}
