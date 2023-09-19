/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:01:09 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/19 10:23:06 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
//# include "mlx/mlx.h"
# include <mlx.h>

typedef struct s_coordinates
{
	int	x;
	int	y;
}			t_coordinates;

typedef struct s_data {
	int				steps;
	int				direction;
	void			*img;
	void			*pacman[4];
	void			*exit_portal;
	void			*wall;
	void			*colectables;
	int				line_length;
	char			**map;
	char			**duplicate_map;
	int				colectables_count;
	int				player_exit;
	t_coordinates	end_game_size;
	t_coordinates	player;
	t_coordinates	exit;
	t_coordinates	wall_size;
	t_coordinates	colectables_size;
	t_coordinates	portal_size;
}				t_data;

typedef struct s_patata {
	t_coordinates	a;
	t_data			img;
	void			*mlx;
	void			*win;
}				t_data_global;

t_coordinates	exit_position(t_data_global *init);
t_coordinates	player_position(t_data_global *init);
t_coordinates	map_lengh_high(char **map);
int				count_colectables(t_data_global *data);
void			check_items(t_data_global *init);
void			ft_funtion(t_data_global *data);
int				key_hook(int key, t_data_global *init);
void			set_up(t_data_global *patata);
void			check_map(t_data_global *init);
char			**open_map(int argc, char **argv, t_data_global *init);
void			close_program(t_data_global *init);
int				close_window(t_data_global *init);
void			free_map(char **map);
void			exit_game(t_data_global *data);
char			**duplicate_map(t_data_global *init);
void			check_accesibility(t_data_global *init);
void			floodfill(char **duplicate, int x, int y);
void			floodfill_duplicate(char **duplicate, int x, int y);
void			check_walls_floodfill(t_data_global *init);
void			free_map(char **map);
void			free_double_pointer(t_data_global *init);

#endif
