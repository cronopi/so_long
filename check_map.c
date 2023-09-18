/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:35:41 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/18 13:56:02 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	check_floors(t_data_global *init)
{
	t_coordinates	player;
	int				i;

	i = 0;
	player = player_position(init);
	floodfill(init->img.duplicate_map, player.x, player.y);
	check_accesibility(init);
	floodfill_duplicate(init->img.duplicate_map, player.x, player.y);
	check_walls_floodfill(init);
	while (init->img.duplicate_map[i] != NULL)
	{
		printf("%s\n", init->img.duplicate_map[i]);
		i++;
	}
}

int	count_lines(t_data_global *init)
{
	int	j;

	j = 0;
	while (init->img.map[j] != NULL)
		j++;
	return (j);
}

void	else_error_map(t_data_global *init)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("2\n", 1);
	free_map(init->img.map);
	mlx_destroy_display(init->mlx);// solo funciona en linux
	free(init->mlx);
	exit(1);
}

void	check_n_and_r(t_data_global *init, int j, size_t check_numbers)
{
	unsigned int	numero;
	int				i;

	i = 0;
	while (i < j)
	{
		numero = ft_strlen(init->img.map[i]);
		if (init->img.map[i][ft_strlen(init->img.map[i]) - 1] == '\n')
		{
			numero--;
			if (init->img.map[i][ft_strlen(init->img.map[i]) - 2] == '\r')
				numero--;
		}
		if (check_numbers == numero)
			i++;
		else
			else_error_map(init);
	}
}

void	check_map(t_data_global *init)
{
	int				i;
	int				j;
	size_t			check_numbers;

	i = 0;
	j = count_lines(init);
	check_numbers = ft_strlen(init->img.map[i]);
	if (init->img.map[i][ft_strlen(init->img.map[i]) - 1] == '\n')
	{
		check_numbers--;
		if (init->img.map[i][ft_strlen(init->img.map[i]) - 2] == '\r')
			check_numbers--;
	}
	check_n_and_r(init, j, check_numbers);
	i = 0;
	init->img.duplicate_map = duplicate_map(init);
	check_items(init);
	check_floors(init);
	while (init->img.duplicate_map[i] != NULL)
	{
		free(init->img.duplicate_map[i]);
		i++;
	}
	free(init->img.duplicate_map);
}
