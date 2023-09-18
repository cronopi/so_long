/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:12:24 by roberto           #+#    #+#             */
/*   Updated: 2023/09/18 10:20:10 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	free_leaks(t_data_global *init)
{
	ft_putstr_fd("Error\n", 1);
	free_map(init->img.duplicate_map);
	free_map(init->img.map);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	exit(1);
}

void	check_walls_floodfill2(t_data_global *init)
{
	t_coordinates	coords;

	coords.x = 0;
	coords.y = 0;
	while (init->img.duplicate_map[coords.y][coords.x] != '\0')
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init);
		coords.x++;
	}
}

void	check_walls_floodfill(t_data_global *init)
{
	t_coordinates	coords;

	coords.x = 0;
	coords.y = 0;
	while (init->img.duplicate_map[coords.y] != NULL)
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init);
		coords.y++;
	}
	coords.y = coords.y - 1;
	while (init->img.duplicate_map[coords.y][coords.x] != '\0')
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init);
		coords.x++;
	}
	coords.x = coords.x - 1;
	while (coords.y >= 0)
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init);
		coords.y--;
	}
	check_walls_floodfill2(init);
}

void	floodfill_duplicate(char **duplicate, int x, int y)
{
	duplicate[y][x] = 'v';
	if (y > 0 && duplicate[y - 1][x] != '1' && duplicate[y - 1][x] != 'v')
		floodfill_duplicate(duplicate, x, y - 1);
	if (duplicate[y][x + 1] != '\0'
		&& duplicate[y][x + 1] != '1' && duplicate[y][x + 1] != 'v')
		floodfill_duplicate(duplicate, x + 1, y);
	if (duplicate[y + 1] != NULL
		&& duplicate[y + 1][x] != '1' && duplicate[y + 1][x] != 'v')
		floodfill_duplicate(duplicate, x, y + 1);
	if (x > 0 && duplicate[y][x - 1] != '1' && duplicate[y][x - 1] != 'v')
		floodfill_duplicate(duplicate, x - 1, y);
	if (y > 0 && x > 0 && duplicate[y - 1][x - 1] != '1'
		&& duplicate[y - 1][x - 1] != 'v')
		floodfill_duplicate(duplicate, x - 1, y - 1);
	if (y > 0 && duplicate[y - 1][x + 1] != '\0'
		&& duplicate[y - 1][x + 1] != '1' && duplicate[y - 1][x + 1] != 'v')
		floodfill_duplicate(duplicate, x + 1, y - 1);
	if (x > 0 && duplicate[y + 1] != NULL && duplicate[y + 1][x - 1] != '1'
		&& duplicate[y + 1][x - 1] != 'v')
		floodfill_duplicate(duplicate, x - 1, y + 1);
	if (duplicate[y + 1] != NULL && duplicate[y + 1][x + 1] != '\0'
		&& duplicate[y + 1][x + 1] != '1' && duplicate[y + 1][x + 1] != 'v')
		floodfill_duplicate(duplicate, x + 1, y + 1);
}

void	floodfill(char **duplicate, int x, int y)
{
	duplicate[y][x] = 'x';
	if (y > 0 && duplicate[y - 1][x] != '1' && duplicate[y - 1][x] != 'x')
		floodfill(duplicate, x, y - 1);
	if (duplicate[y][x + 1] != '\0'
		&& duplicate[y][x + 1] != '1' && duplicate[y][x + 1] != 'x')
		floodfill(duplicate, x + 1, y);
	if (duplicate[y + 1] != NULL
		&& duplicate[y + 1][x] != '1' && duplicate[y + 1][x] != 'x')
		floodfill(duplicate, x, y + 1);
	if (x > 0 && duplicate[y][x - 1] != '1' && duplicate[y][x - 1] != 'x')
		floodfill(duplicate, x - 1, y);
}
