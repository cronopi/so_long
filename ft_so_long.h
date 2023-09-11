/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:01:09 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/05 12:59:50 by roberto          ###   ########.fr       */
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
# include "mlx/mlx.h"
//# include <mlx.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

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
}				t_patata;

t_coordinates	exit_position(char **tokens);
t_coordinates	player_position(char **tokens);
t_coordinates	map_lengh_high(char **map);
int				count_colectables(char **tokens, t_patata *data);
void			check_items(char **tokens);
void			ft_funtion(t_patata *data);
int				key_hook(int key, t_patata *init);
void			set_up(t_patata *patata);
void			check_map(char **tokens, t_patata *init);
char			**open_map(int argc, char **argv, t_patata *init);
void			close_program(t_patata *init);
int				close_window(t_patata *init);
void			free_map(char **map);
void			exit_game(t_patata *data);
char			**duplicate_map(char **tokens);

#endif
