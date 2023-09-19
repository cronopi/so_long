/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:02:23 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/19 16:56:11 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_game(t_data_global *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.pacman[data->img.direction],
		data->img.player.x, data->img.player.y);
	if (data->img.player_exit == 0)
	{
		close_window(&data);
		exit(1);
	}
}

void	more_data(t_data_global *data)
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

void	data1(t_data_global *data, t_coordinates size,
	t_coordinates colectable, t_coordinates wall)
{
	if (data->img.map[size.y][size.x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, 32 + wall.x, 32 + wall.y);
	if (data->img.map[size.y][size.x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.colectables, 32 + colectable.x,
			32 + colectable.y);
	if (data->img.map[size.y][size.x] == 'E'
		&& data->img.colectables_count == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit_portal, 32 + wall.x, 32 + wall.y);
	more_data(data);
}

int	print_main_caracter(t_data_global *data)
{
	t_coordinates	size;
	t_coordinates	colectable;
	t_coordinates	wall;

	ft_memset(&colectable, 0, 2 * sizeof(t_coordinates));
	mlx_clear_window(data->mlx, data->win);
	size.y = 0;
	while (data->img.map[size.y] != NULL)
	{
		size.x = 0;
		while (data->img.map[size.y][size.x] != '\0')
		{
			data1(data, size, colectable, wall);
			wall.x = wall.x + 32;
			colectable.x = colectable.x + 32;
			size.x++;
		}
		colectable.y = colectable.y + 32;
		colectable.x = 0;
		wall.y = wall.y + 32;
		wall.x = 0;
		size.y++;
	}
	exit_game(data);
	return (0);
}

void	ft_funtion(t_data_global *data)
{
	mlx_loop_hook(data->mlx, print_main_caracter, data);
	mlx_loop(data->mlx);
}
