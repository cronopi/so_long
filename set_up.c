/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:45 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 09:28:29 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	set_up(t_patata *patata)
{
	patata->img.direction = 0;
	patata->img.player_exit = 1;
	patata->img.steps = 0;
	patata->img.colectables_count = count_colectables(patata);
	patata->img.exit = exit_position(patata);
	patata->img.player = player_position(patata);
	patata->img.exit.x = (patata->img.exit.x * 32) + 32;
	patata->img.exit.y = (patata->img.exit.y * 32) + 32;
	patata->img.player.x = (patata->img.player.x * 32) + 32;
	patata->img.player.y = (patata->img.player.y * 32) + 32;
	patata->img.exit_portal = mlx_xpm_file_to_image(patata->mlx, "portal.xpm",
			&(patata->img.portal_size.x), &(patata->img.portal_size.y));
	patata->img.wall = mlx_xpm_file_to_image(patata->mlx, "wall.xpm",
			&patata->img.wall_size.x, &patata->img.wall_size.y);
	patata->img.colectables = mlx_xpm_file_to_image(patata->mlx,
			"pacdot_food.xpm", &patata->img.colectables_size.x,
			&patata->img.colectables_size.y);
	patata->img.pacman[0] = mlx_xpm_file_to_image(patata->mlx,
			"pac_open_right.xpm", &(patata->a.x), &(patata->a.y));
	patata->img.pacman[1] = mlx_xpm_file_to_image(patata->mlx,
			"pac_open_up.xpm", &(patata->a.x), &(patata->a.y));
	patata->img.pacman[2] = mlx_xpm_file_to_image(patata->mlx,
			"pac_open_down.xpm", &(patata->a.x), &(patata->a.y));
	patata->img.pacman[3] = mlx_xpm_file_to_image(patata->mlx,
			"pac_open_left.xpm", &(patata->a.x), &(patata->a.y));
}
