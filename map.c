/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:40:53 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/14 14:17:19 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	error_map(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("4\n", 1);
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
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("5\n", 1);
			exit(1);
		}
	}
}

int	fd_and_argc_check(int argc, char **argv, t_patata *init)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("6\n", 1);
		mlx_destroy_display(init->mlx);// no se puede usar en macOS
		free(init->mlx);
		exit(1);
	}
	check_valid_ber(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("7\n", 1);
		//close_program(init);
		mlx_destroy_display(init->mlx);// no se puede usar en macOS
		free(init->mlx);
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
	int		i;
	int		j;

	init->img.map = NULL;
	j = 0;
	fd = fd_and_argc_check(argc, argv, init);
	i = i_loop(fd);
	init->img.map = malloc(sizeof(char *) * (i + 1)); // el i + 1 es necesario?
	if (!init->img.map)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (j < i)
	{
		init->img.map[j] = get_next_line(fd);
		//ft_putstr_fd(init->img.map[j], 2);
		j++;
	}
	init->img.map[j] = NULL;
	if (init->img.map[j - 1][ft_strlen(init->img.map[j - 1]) - 1] == '\n')
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("8\n", 1);
			free_map(init->img.map);
			mlx_destroy_display(init->mlx);// solo funciona en linux
			free(init->mlx);
			exit(1);
		}
	close(fd);
	check_map(init->img.map, init);
	map_lengh_high(init->img.map);
	return (init->img.map);
}
