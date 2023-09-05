/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:40:53 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/05 11:06:25 by rcastano         ###   ########.fr       */
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
	int	check;

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
		if (check == 0)
		{
			ft_putstr_fd("Error: map\n", 2);
			exit(1);
		}
	}
}

int	fd_and_argc_check(int argc, char **argv, t_patata *init)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error: map\n", 2);
		exit(1);
	}
	check_valid_ber(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: map\n", 2);
		close_program(init);
		exit(1);
	}
	return (fd);
}

int	i_loop(int fd)
{
	int		i;
	char	*test;

	i = 0;
	while (1)
	{
		test = get_next_line(fd);
		if (test)
		{
			i++;
			free(test);
		}
		else
			break ;
	}
	return (i);
}

char	**open_map(int argc, char **argv, t_patata *init)
{
	int		fd;
	char	**tokens;
	int		i;
	int		j;

	tokens = NULL;
	j = 0;
	fd = fd_and_argc_check(argc, argv, init);
	i = i_loop(fd);
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
