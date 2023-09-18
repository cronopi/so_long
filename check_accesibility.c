/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accesibility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:54:17 by roberto           #+#    #+#             */
/*   Updated: 2023/09/18 09:47:20 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	check_accesibility(t_data_global *init)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (init->img.duplicate_map[y] != NULL)
	{
		while (init->img.duplicate_map[y][x] != '\0')
		{
			if (init->img.duplicate_map[y][x] == 'E'
				|| init->img.duplicate_map[y][x] == 'C')
			{
				ft_putstr_fd("Error\n", 2);
				free_map(init->img.duplicate_map);
				free_map(init->img.map);
				mlx_destroy_display(init->mlx);// solo funciona en linux
				free(init->mlx);
				exit(1);
			}
			x++;
		}
		y++;
		x = 0;
	}
}
