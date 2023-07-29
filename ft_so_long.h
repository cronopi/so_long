/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:01:09 by rcastano          #+#    #+#             */
/*   Updated: 2023/07/29 16:53:36 by nazurmen         ###   ########.fr       */
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
//# include "mlx.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coordinates
{
	int	x;
	int	y;
}			t_coordinates;

typedef struct	s_data {
	void			*img;
	void			*pacman;
	void			*exit_portal;
	void			*wall;
	void			*colectables;
	int				line_length;
	char			**map;
	int				colectables_count;
	t_coordinates	player;
	t_coordinates	exit;
	t_coordinates	wall_size;
	t_coordinates	colectables_size;
}				t_data;


typedef struct s_patata
{
	t_coordinates	a;
	t_data			img;
	void			*mlx;
	void 			*win;
}			t_patata;

#endif
