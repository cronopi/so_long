/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:40:53 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 11:49:16 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	error_map(void)
{
	perror("Error: map");
	exit(1);
}

void	check_valid_ber(char **argv)
{
	int	i;

	i = 0;
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
		if (check == 0)
		{
			perror("Error: map");
			exit(1);
		}
	}
}

char	**open_map(int argc, char **argv)
{
	int		fd;
	char	**tokens;
	int		i;
	int		j;
	int		check;

	tokens = NULL;
	i = 0;
	j = 0;
	check = 0;
	if (argc != 2)
	{
		perror("Error: map");
		exit(1);
	}
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
		if (check == 0)
		{
			perror("Error: map");
			exit(1);
		}
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("file not found");
		exit(1);
	}
	while (get_next_line(fd))
		i++;
	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (j <= i)
	{
		tokens[j] = get_next_line(fd);
		j++;
	}
	i = 0;
	j = 0;
	while (tokens[i][j])
		j++;
	check_map(tokens);
	map_lengh_high(tokens);
	j = 0;
	close(fd);
	return (tokens);
}
