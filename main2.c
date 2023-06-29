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

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

void	movements_keys(int key, t_patata *init)
{
	printf("test%i\n", key);
	if (key == 65362) // w 119
	{
		init->a.y -= 10;
	}
	else if (key == 65361) // a 97
	{
		init->a.x -= 10;
	}
	else if (key == 65364) // s 115
	{
		init->a.y += 10;
	}
	else if (key == 65363) // d 100
	{
		init->a.x += 10;
	}
}

int	key_hook(int key, t_patata *init)
{
	movements_keys(key, init);
	if (key == 65307)
	{
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	return(0);
}

int	print_main_caracter(t_patata *patata)
{
	mlx_clear_window(patata->mlx, patata->win);
	mlx_put_image_to_window(patata->mlx, patata->win, patata->img.img2, patata->a.x, patata->a.y);
	return (0);
}

void	ft_funtion(t_patata *patata)
{
	mlx_loop_hook(patata->mlx, print_main_caracter, patata);
	//mlx_loop_hook(patata->mlx, draw_circle, patata);
	mlx_loop(patata->mlx);
}
t_patata	set_up(t_vars	vars, t_data img)
{
	t_patata		patata;

	patata.a.x = 100;
	patata.a.y = 100;
	patata.mlx = vars.mlx;
	patata.win = vars.win;
	patata.img.img2 = img.img2;
	patata.img.img2 = mlx_xpm_file_to_image(patata.mlx, "logo copy.xpm", &(patata.a.x), &(patata.a.y));
	return (patata);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_patata init;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (1);
	}
	init = set_up(vars, img);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &init);

	init.img.img =  mlx_new_image(init.mlx, WINDOW_WIDTH, WINDOW_HEIGHT); // mlx setup

	ft_funtion(&init);

	free(vars.mlx);
	return (0);
}
