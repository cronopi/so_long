/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:40:53 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/01 14:23:22 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	error_map(void)
{
	ft_putstr_fd("Error: map\n", 2);
	exit(1);
}

void	check_valid_ber(char **argv)
{
	int	i;
	int		check;

	i = 0;
	check = 0;
	if (argv[1])
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == '.' && argv[1][i + 1] == 'b'
			&& argv[1][i + 2] == 'e'
			&& argv[1][i + 3] == 'r' && argv[1][i + 4] == '\0')
				check = 1;
			i++;
		}
		if (check == 0)// aqui no hace falta liberar el mapa pero si liberar mlx y destroy display
		{
			ft_putstr_fd("Error: map\n", 2);
			exit(1);
		}
	}
}

char	**open_map(int argc, char **argv, t_patata *init)
{
	int		fd;
	char	**tokens;
	int		i;
	int		j;
	char	*test;

	tokens = NULL;
	j = 0;
	if (argc != 2)// aqui no hace falta liberar el mapa pero si liberar mlx y destroy display
	{
		ft_putstr_fd("Error: map\n", 2);
		exit(1);
	}
	check_valid_ber(argv);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: map\n", 2);
		close_program(init);
		exit(1);
	}
	while (1)
	{
		test = get_next_line(fd);
		if (test)
		{
			i++;
			free(test);
		}
		else
			break;
	}
	tokens = malloc(sizeof(char *) * (i + 1)); // el i + 1 es necesario?
	if (!tokens)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (j <= i)
	{
		tokens[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	check_map(tokens, init);
	map_lengh_high(tokens);
	return (tokens);
}
