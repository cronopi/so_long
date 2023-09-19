/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:36:07 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/19 08:57:20 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	items_errors(int e, int p, int c, t_data_global *init)
{
	if (e != 1 || p != 1 || c < 1)
	{
		ft_putstr_fd("Error\n", 1);
		free_map(init->img.duplicate_map);
		free_map(init->img.map);
		//mlx_destroy_display(init->mlx);// solo funciona en linux
		free(init->mlx);
		exit(1);
	}
}

void	pec_count(t_data_global *init, int *e, int *c, t_coordinates coords)
{
	if (init->img.duplicate_map[coords.x][coords.y] == 'E')
		(*e)++;
	else if (init->img.duplicate_map[coords.x][coords.y] == 'C')
		(*c)++;
	else if (init->img.duplicate_map[coords.x][coords.y] != '1'
		&& init->img.duplicate_map[coords.x][coords.y] != '0'
		&& init->img.duplicate_map[coords.x][coords.y] != '\r'
		&& init->img.duplicate_map[coords.x][coords.y] != '\n')
		items_errors(0, 0, 0, init);
}

void	check_items(t_data_global *init)
{
	t_coordinates	coords;
	int				p;
	int				e;
	int				c;

	p = 0;
	e = 0;
	c = 0;
	coords.x = 0;
	coords.y = 0;
	while (init->img.duplicate_map[coords.x] != NULL)
	{
		while (init->img.duplicate_map[coords.x][coords.y] != '\0')
		{
			if (init->img.duplicate_map[coords.x][coords.y] == 'P')
				p++;
			else
				pec_count(init, &e, &c, coords);
			coords.y++;
		}
		coords.x++;
		coords.y = 0;
	}
	items_errors(e, p, c, init);
}
