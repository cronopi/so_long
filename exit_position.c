/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:52:20 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 08:33:53 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_coordinates	exit_position(t_patata *init)
{
	t_coordinates	exit;

	exit.x = 0;
	exit.y = 0;
	while (init->img.map[exit.y][exit.x])
	{
		while (init->img.map[exit.y][exit.x] != '\0')
		{
			if (init->img.map[exit.y][exit.x] == 'E')
				return (exit);
			exit.x++;
		}
		exit.y++;
		exit.x = 0;
	}
	return (exit);
}
