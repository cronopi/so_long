/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:06:57 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 09:26:58 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_coordinates	player_position(t_patata *init)
{
	t_coordinates	player;

	player.x = 0;
	player.y = 0;
	while (init->img.map[player.y][player.x])
	{
		while (init->img.map[player.y][player.x] != '\0')
		{
			if (init->img.map[player.y][player.x] == 'P')
				return (player);
			player.x++;
		}
		player.y++;
		player.x = 0;
	}
	return (player);
}
