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

// cmprobar que lo pintado tiene jugador monedas salida etc ACCESIBLE
// contar numero de movimientos

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
	return (player);
}

t_coordinates	exit_position(char **tokens)
{
	t_coordinates	exit;

	exit.x = 0;
	exit.y = 0;
	while(tokens[exit.y][exit.x])
	{
		while (tokens[exit.y][exit.x] != '\0')
		{
			if (tokens[exit.y][exit.x] == 'E')
				return (exit);
			exit.x++;
		}
		exit.y++;
		exit.x = 0;
	}
	return (exit);
}

void floodfill(char **duplicate, int x, int y)
{
	duplicate[y][x] = 'v';

	if ( y >= 0 && duplicate[y - 1][x] != '1' && duplicate[y - 1][x] != 'v')
		floodfill(duplicate, x, y - 1);
	if (duplicate[y][x + 1] != '\0' && duplicate[y][x + 1] != '1' && duplicate[y][x + 1] != 'v')
		floodfill(duplicate, x + 1, y);
	if (duplicate[y + 1][0] !=  '\0' && duplicate[y + 1][x] != '1' && duplicate[y + 1][x] != 'v')
		floodfill(duplicate, x, y + 1);
	if (x >= 0 && duplicate[y][x - 1] != '1' && duplicate[y][x - 1] != 'v')
		floodfill(duplicate, x - 1, y);
}

void check_floors(char **duplicate)
{
	t_coordinates	player;

	player = player_position(duplicate);
	duplicate[player.y][player.x] = 'v';
	floodfill(duplicate, player.x, player.y);
}

int	count_colectables(char **tokens, t_patata *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->img.colectables_count = 0;
	while(tokens[i] != NULL)
	{
		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'C')
				data->img.colectables_count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (data->img.colectables_count);
}

void	check_items(char **tokens)
{
	int		i;
	int		j;
	char	P;
	char	E;
	char	C;

	P = 0;
	E = 0;
	C = 0;
	i = 0;
	j = 0;
	while(tokens[i] != NULL)
	{
		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'P')
				P++;
			else if (tokens[i][j] == 'E')
				E++;
			else if (tokens[i][j] == 'C')
				C++;
			j++;
		}
		i++;
		j = 0;
	}
	if (E != 1)
	{
		perror("Error: map");
		exit(1);
	}
	else if (P != 1)
	{
		perror("Error: map");
		exit(1);
	}
	else if (C < 1)
	{
		perror("Error: map");
		exit(1);
	}
}

char	**duplicate_map(char **tokens)
{
	int	y;
	int x;
	char **duplicate;

	x = 0;
	y = 0;
	while(tokens[y] != NULL)
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
	while(y != 0)
	{
		y--;
		duplicate[y] = ft_strdup(tokens[y]);
	}
	return (duplicate);
}

void	check_map(char **tokens)
{
	int		i;
	int		j;
	size_t	check_numbers;
	char	**duplicate_maps;

	i = 0;
	j = 0;
	while(tokens[j] != NULL)
	{
		while (tokens[j][i] != '\0')
			i++;
		j++;
		i = 0;
	}
	i = 0;
	if (j < 3)
	{
		perror("Error: map");
		exit(1);
	}
	check_numbers = ft_strlen(tokens[i]);
	while (i < j)
	{
		if (check_numbers == ft_strlen(tokens[i]))
			i++;
		else
			perror("Error: map");
	}
	duplicate_maps = duplicate_map(tokens);
	check_floors(duplicate_maps);
}

t_coordinates	map_lengh_high(char **map)
{
	t_coordinates size;

	size.y = 0;
	while(map[size.y] != NULL)
	{
		size.x = 0;
		while (map[size.y][size.x] != '\0')
			size.x++;
		size.y++;
	}
	return (size);
}

char **open_map(int argc, char **argv)
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
		return (0);
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
	check_map(tokens);
	//check_floors(tokens);
	map_lengh_high(tokens);
	j = 0;
	close(fd);
	(void) argc;
	(void) argv;
	return (tokens);
}

int	print_main_caracter(t_patata *data)
{
	t_coordinates	size;
	int				colectable_x;
	int				colectable_y;
	int				wall_x;
	int				wall_y;

	wall_x = 0;
	wall_y = 0;
	colectable_x = 0;
	colectable_y = 0;
	mlx_clear_window(data->mlx, data->win);
	size.y = 0;
	while(data->img.map[size.y] != NULL)
	{
		size.x = 0;
		while (data->img.map[size.y][size.x] != '\0')
		{
			if (data->img.map[size.y][size.x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 32 + wall_x, 32 + wall_y);
			if (data->img.map[size.y][size.x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.colectables, 32 + colectable_x, 32 + colectable_y);
			if (data->img.map[((data->img.player.y -32 ) / 32)][(data->img.player.x - 32 ) / 32] == 'C')
			{
				data->img.map[((data->img.player.y -32 ) / 32)][(data->img.player.x - 32 ) / 32] = '0';
				data->img.colectables_count--;
				ft_printf("numero de colecionables: %d\n", data->img.colectables_count);
			}
			wall_x = wall_x + 32;
			colectable_x = colectable_x + 32;
			size.x++;
		}
		colectable_y = colectable_y + 32;
		colectable_x = 0;
		wall_y = wall_y + 32;
		wall_x = 0;
		size.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.pacman, data->img.player.x, data->img.player.y);
	if (!(data->img.colectables_count > 0))
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_portal, data->img.exit.x, data->img.exit.y);
	return (0);
}

void	ft_funtion(t_patata *data)
{
	mlx_loop_hook(data->mlx, print_main_caracter, data);
	mlx_loop(data->mlx);
}

void	movements_keys(int key, t_patata *init)
{

	if (key == 65362)
	{
		if (!(init->img.map[((init->img.player.y -32 ) / 32) - 1][(init->img.player.x - 32 ) / 32] == '1'))
		{
			init->img.player.y -= 32;
		}
	}
	else if (key == 65361)
	{
		if (!(init->img.map[(init->img.player.y - 32 ) / 32][((init->img.player.x - 32 ) / 32) - 1] == '1'))
		{
			init->img.player.x -= 32;
		}
	}
	else if (key == 65364)
	{
		if (!(init->img.map[((init->img.player.y - 32 ) / 32) + 1][(init->img.player.x - 32 ) / 32] == '1'))
		{
			init->img.player.y += 32;
		}
	}
	else if (key == 65363)
	{
		if (!(init->img.map[(init->img.player.y - 32 ) / 32][((init->img.player.x - 32 ) / 32) + 1] == '1'))
		{
			init->img.player.x += 32;
		}
	}
}

int	key_hook(int key, t_patata *init)
{
	movements_keys(key, init);
	if (key == 65307)
	{
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	return(0);
}

void	set_up(t_vars	vars, t_patata *patata)
{
	patata->img.colectables_count = count_colectables(patata->img.map, patata);
	patata->img.exit = exit_position(patata->img.map);
	patata->img.player = player_position(patata->img.map);
	patata->img.exit.x = (patata->img.exit.x * 32) + 32;
	patata->img.exit.y = (patata->img.exit.y * 32) + 32;
	patata->img.player.x = (patata->img.player.x * 32) + 32;
	patata->img.player.y = (patata->img.player.y * 32) + 32;
	patata->mlx = vars.mlx;
	patata->win = vars.win;
	patata->img.exit_portal =  mlx_xpm_file_to_image(patata->mlx, "portal.xpm",  &(patata->a.x), &(patata->a.y));
	patata->img.wall =  mlx_xpm_file_to_image(patata->mlx, "wall.xpm", &patata->img.wall_size.x, &patata->img.wall_size.y);
	patata->img.colectables =  mlx_xpm_file_to_image(patata->mlx, "pacdot_food.xpm", &patata->img.colectables_size.x, &patata->img.colectables_size.y);
	patata->img.pacman = mlx_xpm_file_to_image(patata->mlx, "pac_open_right.xpm", &(patata->a.x), &(patata->a.y));
}

int	main(int argc, char **argv)
{
	t_vars			vars;
	t_coordinates	map_size;
	t_patata		init;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	init.img.map = open_map(argc, argv);
	map_size = map_lengh_high(init.img.map);
	vars.win = mlx_new_window(vars.mlx, (map_size.x * 32) + 64, (map_size.y * 32) + 64, "so_long");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (1);
	}
	set_up(vars, &init);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &init);
	init.img.img =  mlx_new_image(init.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_funtion(&init);
	mlx_loop(vars.mlx);

	free(vars.mlx);
	return (0);
}
