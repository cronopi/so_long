/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:35:41 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 10:50:31 by rcastano         ###   ########.fr       */
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

char	**duplicate_map(char **tokens)
{
	int		y;
	int		x;
	char	**duplicate;

	x = 0;
	y = 0;
	while (tokens[y] != NULL)
	{
		while (tokens[y][x] != '\0')
			x++;
		y++;
		x = 0;
	}
	duplicate = malloc(sizeof(char *) * (y + 1));
	if (!duplicate)
		return (0);
	duplicate[y] = NULL;
	while (y != 0)
	{
		y--;
		duplicate[y] = ft_strdup(tokens[y]);
	}
	return (duplicate);
}

/* int	count_lines(char tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[j] != NULL)
	{
		while (tokens[j][i] != '\0')
			i++;
		j++;
		i = 0;
	}
	if (j < 3)
	{
		ft_putstr_fd("Error: map\n", 2);
		exit(1);
	} 
	return (j);
} */

/* void	check_left_to_right(char **tokens, int j)
{
	int	i;
	
	i = 0;
	while (i < j)
	{
		if (check_numbers == ft_strlen(tokens[i]))
			i++;
		else
		{
			ft_putstr_fd("Error: map\n", 2);
			exit(1);
		}
	}
} */

void	check_map(char **tokens)
{
	int		i;
	int		j;
	size_t	check_numbers;
	char	**duplicate_maps;

	i = 0;
	j = 0;
	while (tokens[j] != NULL)
	{
		while (tokens[j][i] != '\0')
			i++;
		j++;
		i = 0;
	}
	if (j < 3)
	{
		ft_putstr_fd("Error: map\n", 2);
		exit(1);
	}
	//j =	count_lines(tokens);
	check_numbers = ft_strlen(tokens[i]);
	i = 0;
	while (i < j)
	{
		if (check_numbers == ft_strlen(tokens[i]))
			i++;
		else
		{
			ft_putstr_fd("Error: map\n", 2);
			exit(1);
		}
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
