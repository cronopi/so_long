/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:40:55 by rcastano          #+#    #+#             */
/*   Updated: 2023/06/19 16:33:20 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_so_long.h"

//cerrar la ventana
// que es un floodfill
//mapa validarlo procesar texto
//game loop
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

void reed_map(void)
{
	int fd;

	fd = open("map.ber", O_RDONLY);
	get_next_line(fd);
	//comrpobar que el mapa sea válido

}

int	key_hook(int key, t_vars	vars)
{
	(void) key;
	(void) vars;
	return(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	reed_map();
	vars.mlx = mlx_init();

	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "patata");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (1);
	}
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);

/*
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_loop_end(vars.mlx);
*/
	free(vars.mlx);
	return (0);
}
