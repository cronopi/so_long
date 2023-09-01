/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:56:03 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 13:21:24 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	more_movements_keys(int key, t_patata *init)
{
	//if (key == 1)
	if (key == 65364)
	{
		if (!(init->img.map[((init->img.player.y - 32) / 32) + 1]
				[(init->img.player.x - 32) / 32] == '1'))
		{
			init->img.player.y += 32;
			init->img.steps++;
			init->img.direction = 2;
		}
	}
	//else if (key == 2)
	else if (key == 65363)
	{
		if (!(init->img.map[(init->img.player.y - 32) / 32]
				[((init->img.player.x - 32) / 32) + 1] == '1'))
		{
			init->img.player.x += 32;
			init->img.steps++;
			init->img.direction = 0;
		}
	}
}

void	movements_keys(int key, t_patata *init)
{
	if (init->img.player_exit == 1)
	{
		//if (key == 13)
		if(key == 65362)
		{
			if (!(init->img.map[((init->img.player.y -32) / 32) - 1]
					[(init->img.player.x - 32) / 32] == '1'))
			{
				init->img.player.y -= 32;
				init->img.steps++;
				init->img.direction = 1;
			}
		}
		//else if (key == 0)
		else if(key == 65361)
		{
			if (!(init->img.map[(init->img.player.y - 32) / 32]
					[((init->img.player.x - 32) / 32) - 1] == '1'))
			{
				init->img.player.x -= 32;
				init->img.steps++;
				init->img.direction = 3;
			}
		}
		more_movements_keys(key, init);
/* 		else if (key == 1) // 65364
		{
			if (!(init->img.map[((init->img.player.y - 32) / 32) + 1]
					[(init->img.player.x - 32) / 32] == '1'))
			{
				init->img.player.y += 32;
				init->img.steps++;
				init->img.direction = 2;
			}
		}
		else if (key == 2) // 65363
		{
			if (!(init->img.map[(init->img.player.y - 32) / 32]
					[((init->img.player.x - 32) / 32) + 1] == '1'))
			{
				init->img.player.x += 32;
				init->img.steps++;
				init->img.direction = 0;
			}
		} */
	}
}

int	key_hook(int key, t_patata *init)
{
	movements_keys(key, init);
	printf("numero de pasos: %d\n", init->img.steps);
	//if (key == 53)
	if (key == 65307)
		mlx_destroy_window(init->mlx, init->win);
	return (0);
}
