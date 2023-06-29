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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	printf("x=%i y=%i color=%i\n", x, y, color);
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* void reed_map(void)
{
	int fd;

	fd = open("map.ber", O_RDONLY);
	get_next_line(fd);
	//comrpobar que el mapa sea válido

} */

int	key_hook(int key, t_vars	*vars)
{
	printf("test%i\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
/* 	if (key == 119) // Key_W
	{
		t_coodinates-> -= 10;
	}
	if (key == 97) // Key_A
	{
		t_coodinates-> -= 10;
	}
	if (key == 115) // Key_S
	{
		t_coodinates-> += 10;
	}
	if (key == 100) // Key_D
	{
		t_coodinates-> += 10;
	} */
	//mlx_clear_window();

	return(0);
}

void set_up_circle(t_coordinates *square)
{
	square->x = 200;
	square->y = 200;
}

int draw_circle(void *patata)
{
	int	lengh;
	int	x;
	int	y;
	t_patata *test;

	test = patata;
	lengh = 25;
	x = 0;
	y = 0;
	while(y < lengh)
	{
		my_mlx_pixel_put(test->img, test->a.x + x, test->a.y + y, 0x00FF0000);
		my_mlx_pixel_put(test->img, 200, 200 , 0xFFFFFFFF);
		my_mlx_pixel_put(test->img, 201, 201 , 0xFFFFFF00);
		x++;
		if (x == lengh)
		{
			x = 0;
			y++;
		}
	}
	mlx_put_image_to_window(test->mlx, test->win, test->img, 0, 0);
	return 1;
}

int	main(void)
{
	t_vars			vars;
	t_data			img;
	t_coordinates square;
	//int width, height;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "patata");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (1);
	}
	img.img =  mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);// mlx setup

	//img.img2 = mlx_xpm_file_to_image(vars.mlx, "logo copy.xpm", &width, &height);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img2, 0, 0);

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	set_up_circle(&square);
	t_patata patata;
	patata.a.x = square.x;
	patata.a.y = square.y;
	patata.img = &img;
	patata.mlx = vars.mlx;
	patata.win = vars.win;
	mlx_loop_hook(vars.mlx, draw_circle, &patata);
	mlx_loop(vars.mlx);

	//mlx_key_hook(vars.win, key_hook, &vars);

	free(vars.mlx);
	return (0);
}
