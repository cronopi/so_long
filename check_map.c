/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:35:41 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/05 10:28:58 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	floodfill(char **duplicate, int x, int y)
{
	duplicate[y][x] = 'v';
	if (y >= 0 && duplicate[y - 1][x] != '1' && duplicate[y - 1][x] != 'v')
		floodfill(duplicate, x, y - 1);
	if (duplicate[y][x + 1] != '\0'
		&& duplicate[y][x + 1] != '1' && duplicate[y][x + 1] != 'v')
		floodfill(duplicate, x + 1, y);
	if (duplicate[y + 1][0] != '\0'
		&& duplicate[y + 1][x] != '1' && duplicate[y + 1][x] != 'v')
		floodfill(duplicate, x, y + 1);
	if (x >= 0 && duplicate[y][x - 1] != '1' && duplicate[y][x - 1] != 'v')
		floodfill(duplicate, x - 1, y);
}

void	check_floors(char **duplicate)
{
	t_coordinates	player;

	player = player_position(duplicate);
	duplicate[player.y][player.x] = 'v';
	floodfill(duplicate, player.x, player.y);
}

int	count_lines(char **tokens, t_patata *init)
{
	int	i;
	int	j;

	j = 0;
	while (tokens[j] != NULL)
	{
		i = 0;
		while (tokens[j][i] != '\0')
			i++;
		j++;
	}
	if (j < 3 || i < 3)
	{
		ft_putstr_fd("Error: map\n", 2);
		close_program(init);
		exit(1);
	}
	i = 0;
	return (j);
}

void	else_error_map(char **tokens, t_patata *init)
{
	ft_putstr_fd("Error: map\n", 2);
	free_map(tokens);
	//mlx_destroy_display(init->mlx); solo funciona en linux
	free(init->mlx);
	exit(1);
}

void	check_map(char **tokens, t_patata *init)
{
	int		i;
	int		j;
	size_t	check_numbers;
	char	**duplicate_maps;

	i = 0;
	j = count_lines(tokens, init);
	check_numbers = ft_strlen(tokens[i]);
	while (i < j)
	{
		if (check_numbers == ft_strlen(tokens[i]))
			i++;
		else
			else_error_map(tokens, init);
	}
	i = 0;
	duplicate_maps = duplicate_map(tokens);
	check_floors(duplicate_maps);
	while (duplicate_maps[i] != NULL)
	{
		free(duplicate_maps[i]);
		i++;
	}
	free(duplicate_maps);
}
