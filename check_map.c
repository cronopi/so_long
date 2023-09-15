/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:35:41 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 10:45:50 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void free_leaks(char **duplicate)
{
	ft_putstr_fd("Error\n", 1);
	(void)duplicate;
	//free_map(duplicate);
	exit(1);
}

void	check_walls_floodfill(t_patata *init)
{
	t_coordinates	coords;

	coords.x = 0;
	coords.y = 0;
	while (init->img.duplicate_map[coords.y] != NULL)
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init->img.duplicate_map);
		coords.y++;
	}
	coords.y = coords.y - 1;
	while (init->img.duplicate_map[coords.y][coords.x] != '\0')
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init->img.duplicate_map);
		coords.x++;
	}
	coords.x = coords.x - 1;
	while (coords.y >= 0)
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init->img.duplicate_map);
		coords.y--;
	}
	coords.y = 0;
	coords.x = 0;
	while (init->img.duplicate_map[coords.y][coords.x] != '\0')
	{
		if (init->img.duplicate_map[coords.y][coords.x] == 'v')
			free_leaks(init->img.duplicate_map);
		coords.x++;
	}
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
	if (y > 0 && x > 0 && duplicate[y - 1][x - 1] != '1' && duplicate[y - 1][x - 1] != 'v')
		floodfill_duplicate(duplicate, x - 1, y - 1);
	if (y > 0 && duplicate[y - 1][x + 1] != '\0' && duplicate[y - 1][x + 1] != '1' && duplicate[y - 1][x + 1] != 'v')
		floodfill_duplicate(duplicate, x + 1, y - 1);
	if (x > 0 && duplicate[y + 1] != NULL && duplicate[y + 1][x - 1] != '1' && duplicate[y + 1][x - 1] != 'v')
		floodfill_duplicate(duplicate, x - 1, y + 1);
	if(duplicate[y + 1] != NULL && duplicate[y + 1][x + 1] != '\0' && duplicate[y + 1][x + 1] != '1' && duplicate[y + 1][x + 1] != 'v')
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

void	check_floors(t_patata *init)
{
	t_coordinates	player;

	player = player_position(init);
	floodfill_duplicate(init->img.duplicate_map, player.x, player.y);
	check_walls_floodfill(init);
	//free_map(init->img.duplicate_map);
	floodfill(init->img.duplicate_map, player.x, player.y);
	check_accesibility(init);
	int i = 0;
	while (init->img.duplicate_map[i] != NULL)
	{
		printf("%s\n", init->img.duplicate_map[i]);
		i++;
	}

}

int	count_lines(t_patata *init)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (init->img.map[j] != NULL)
	{
		i = 0;
		while (init->img.map[j][i] != '\0')
			i++;
		j++;
	}
	if (j < 3 || i < 3)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("3\n", 1);
		free_map(init->img.map);
		mlx_destroy_display(init->mlx);// solo funciona en linux
		free(init->mlx);
		exit(1);
	}
	i = 0;
	return (j);
}

void	else_error_map(t_patata *init)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("2\n", 1);
	free_map(init->img.map);
	mlx_destroy_display(init->mlx);// solo funciona en linux
	free(init->mlx);
	exit(1);
}

void	check_map(t_patata *init)
{
	int		i;
	int		j;
	size_t	check_numbers;
	unsigned int numero;

	i = 0;
	j = count_lines(init);
	check_numbers = ft_strlen(init->img.map[i]);
	if (init->img.map[i][ft_strlen(init->img.map[i]) - 1] == '\n')
	{
		check_numbers--;
		if (init->img.map[i][ft_strlen(init->img.map[i]) - 2] == '\r')
			check_numbers--;
	}
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
