/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:40:53 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/19 08:36:02 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	check_valid_ber(char **argv, t_data_global *init)
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
			//mlx_destroy_display(init->mlx);// no se puede usar en macOS
			free(init->mlx);
			exit(1);
		}
	}
}

int	fd_and_argc_check(int argc, char **argv, t_data_global *init)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		//mlx_destroy_display(init->mlx);// no se puede usar en macOS
		free(init->mlx);
		exit(1);
	}
	check_valid_ber(argv, init);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 1);
		//mlx_destroy_display(init->mlx);// no se puede usar en macOS
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
		{
			break ;
		}
	}
	return (i);
}

void	line_leap(t_data_global *init, int j)
{
	if (init->img.map[j - 1][ft_strlen(init->img.map[j - 1]) - 1] == '\n')
	{
		ft_putstr_fd("Error\n", 1);
		free_map(init->img.map);
		//mlx_destroy_display(init->mlx);// solo funciona en linux
		free(init->mlx);
		exit(1);
	}
}

char	**open_map(int argc, char **argv, t_data_global *init)
{
	int		fd;
	int		i;
	int		j;

	init->img.map = NULL;
	j = 0;
	fd = fd_and_argc_check(argc, argv, init);
	i = i_loop(fd);
	init->img.map = malloc(sizeof(char *) * (i + 1));
	if (!init->img.map)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (j < i)
	{
		init->img.map[j] = get_next_line(fd);
		j++;
	}
	init->img.map[j] = NULL;
	line_leap(init, j);
	close(fd);
	check_map(init);
	map_lengh_high(init->img.map);
	return (init->img.map);
}
