/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:35:41 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/07 01:25:58 by roberto          ###   ########.fr       */
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
		ft_putstr_fd("Error\n", 1);
		mlx_destroy_display(init->mlx);// solo funciona en linux
		free(init->mlx);
		exit(1);
	}
	i = 0;
	return (j);
}

void	else_error_map(char **tokens, t_patata *init)
{
	ft_putstr_fd("Error\n", 1);
	free_map(tokens);
	mlx_destroy_display(init->mlx);// solo funciona en linux
	free(init->mlx);
	exit(1);
}

void	check_map(char **tokens, t_patata *init)
{
	int		i;
	int		j;
	size_t	check_numbers;
	char	**duplicate_maps;
	unsigned int numero;

	j = 0;
	i = 0;

	j = count_lines(tokens, init);
	check_numbers = ft_strlen(tokens[i]);
	if (tokens[i][ft_strlen(tokens[i]) - 1] == '\n')
		check_numbers--;
	while (i < j)
	{

		ft_putnbr_fd(i, 2);
		ft_putstr_fd(" ", 2);
		numero = ft_strlen(tokens[i]);
/* 		if (tokens[i][ft_strlen(tokens[i]) - 1] == '\n')
		{
			ft_putstr_fd("entra\n", 2);
			ft_putnbr_fd(numero, 2);
			numero--;
		} */
		ft_putstr_fd("comparacion", 2);
		ft_putnbr_fd(check_numbers, 2);
		ft_putstr_fd(" ", 2);
		ft_putnbr_fd(numero, 2);
		ft_putstr_fd("\n", 2);

		if (check_numbers == numero)
		//if (check_numbers == ft_strlen(tokens[i]))
		{
			i++;
		}
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
