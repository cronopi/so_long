/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:02:23 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/04 14:06:00 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_game(t_patata *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.pacman[data->img.direction],
		data->img.player.x, data->img.player.y);
	if (data->img.player_exit == 0)
	{
		close_window(data);
		close_program(data);
		exit(1);
	}
}

/* void	more_data(t_patata *data)
{
	if (data->img.map[((data->img.player.y -32) / 32)]
		[(data->img.player.x - 32) / 32] == 'C')
	{
		data->img.map[((data->img.player.y -32) / 32)]
		[(data->img.player.x - 32) / 32] = '0';
		data->img.colectables_count--;
		ft_printf("numero de colecionables: %d\n",
			data->img.colectables_count);
	}
	if (data->img.map[((data->img.player.y -32) / 32)]
		[(data->img.player.x - 32) / 32] == 'E'
		&& data->img.colectables_count == 0)
	{
		data->img.player_exit = 0;
		data->img.map[((data->img.player.y -32) / 32)]
		[(data->img.player.x - 32) / 32] = '0';
		ft_printf("Fin de la partida!\n");
	}
}

void	data(t_patata *data)
{
	if (data->img.map[size.y][size.x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, 32 + wall_x, 32 + wall_y);
	if (data->img.map[size.y][size.x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.colectables, 32 + colectable_x,
			32 + colectable_y);
	if (data->img.map[size.y][size.x] == 'E'
		&& data->img.colectables_count == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit_portal, 32 + wall_x, 32 + wall_y);
} */

int	print_main_caracter(t_patata *data)
{
	t_coordinates	size;
	int				colectable_x;
	int				colectable_y;
	int				wall_x;
	int				wall_y;

	wall_x = 0;
	wall_y = 0;
	colectable_x = 0;
	colectable_y = 0;
	mlx_clear_window(data->mlx, data->win);
	size.y = 0;
	while (data->img.map[size.y] != NULL)
	{
		size.x = 0;
		while (data->img.map[size.y][size.x] != '\0')
		{
			//data(data);
			//more_data(data);
			if (data->img.map[size.y][size.x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.wall, 32 + wall_x, 32 + wall_y);
			if (data->img.map[size.y][size.x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.colectables, 32 + colectable_x,
					32 + colectable_y);
			if (data->img.map[size.y][size.x] == 'E'
				&& data->img.colectables_count == 0)
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.exit_portal, 32 + wall_x, 32 + wall_y);
			if (data->img.map[((data->img.player.y -32) / 32)]
				[(data->img.player.x - 32) / 32] == 'C')
			{
				data->img.map[((data->img.player.y -32) / 32)]
				[(data->img.player.x - 32) / 32] = '0';
				data->img.colectables_count--;
				ft_printf("numero de colecionables: %d\n",
					data->img.colectables_count);
			}
			if (data->img.map[((data->img.player.y -32) / 32)]
				[(data->img.player.x - 32) / 32] == 'E'
				&& data->img.colectables_count == 0)
			{
				data->img.player_exit = 0;
				data->img.map[((data->img.player.y -32) / 32)]
				[(data->img.player.x - 32) / 32] = '0';
				ft_printf("Fin de la partida!\n");
			}
			wall_x = wall_x + 32;
			colectable_x = colectable_x + 32;
			size.x++;
		}
		colectable_y = colectable_y + 32;
		colectable_x = 0;
		wall_y = wall_y + 32;
		wall_x = 0;
		size.y++;
	}
	exit_game(data);
/* 	mlx_put_image_to_window(data->mlx, data->win,
		data->img.pacman[data->img.direction],
		data->img.player.x, data->img.player.y);
	if (data->img.player_exit == 0)
	{
		close_window(data);
		close_program(data);
		exit(1);
	} */
	return (0);
}

void	ft_funtion(t_patata *data)
{
	mlx_loop_hook(data->mlx, print_main_caracter, data);
	mlx_loop(data->mlx);
}
