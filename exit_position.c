/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:52:20 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 10:52:21 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_coordinates	exit_position(char **tokens)
{
	t_coordinates	exit;

	exit.x = 0;
	exit.y = 0;
	while (tokens[exit.y][exit.x])
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
