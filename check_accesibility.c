/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accesibility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:54:17 by roberto           #+#    #+#             */
/*   Updated: 2023/09/14 14:10:49 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	check_accesibility(char **duplicate, t_patata *init)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (duplicate[y] != NULL)
	{
		while (duplicate[y][x] != '\0')
		{
			if (duplicate[y][x] == 'E' || duplicate[y][x] == 'C')
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("es aqui?\n", 1);
				free_map(duplicate);
				//free_map(init->img.map);
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
