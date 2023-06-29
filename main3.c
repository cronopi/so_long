/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:40:55 by rcastano          #+#    #+#             */
/*   Updated: 2023/06/21 14:56:104 by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_so_long.h"

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

t_coordinates	player_position(char **tokens)
{
	t_coordinates	player;

	player.x = 0;
	player.y = 0;
	while(tokens[player.y][player.x])
	{
		while (tokens[player.y][player.x] != '\0')
		{
			if (tokens[player.y][player.x] == 'P')
				return (player);
			player.x++;
		}
		player.y++;
		player.x = 0;
	}
	player.y = -1;
	player.x = -1;
	return (player);
}

void check_floors(char **tokens)
{
	t_coordinates	player;

	player = player_position(tokens);
	printf("pero no ola de mas ola de saludo: %i %i\n", player.y, player.x);
	tokens[player.y][player.x] = 'v';
}

void	check_map(char **tokens)
{
	int		i;
	int		j;
/* 	char	P;
	char	E;
	char	C;

	P = 0;
	E = 0;
	C = 0; */
	i = 0;
	j = 0;
	while(tokens[i][j])
	{

	}
	// que no contenta mas de una salida y mas de una posicion inicial
	// que de las filas sea la misma cantidad de números
	//error mas mensaje explicito
	//duplicar mapa
}

void open_map(int argc, char **argv)
{
	int	fd;
	char **tokens;
	int	i;
	int j;

	tokens = NULL;
	i = 0;
	j = 0;
/* 	if (argc != 2)
	{
		perror("Error: map");
		exit(1);
	} */

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("file not found");
		exit(1);
	}

	while(get_next_line(fd))
		i++;
	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
		return ;
	close(fd);
	fd = open("map.ber", O_RDONLY);
	while (j <= i)
	{
		tokens[j] = get_next_line(fd);
		j++;
	}
	i = 0;
	j = 0;
	while(tokens[i][j])
		j++;
	//check_map(tokens);
	check_floors(tokens);
	close(fd);
	(void) argc;
	(void) argv;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (1);
	}
	open_map(argc, argv);
	mlx_loop(vars.mlx);


	free(vars.mlx);
	return (0);
}
