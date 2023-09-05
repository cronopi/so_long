/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:06:57 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/05 11:07:17 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_coordinates	player_position(char **tokens)
{
	t_coordinates	player;

	player.x = 0;
	player.y = 0;
	while (tokens[player.y][player.x])
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
