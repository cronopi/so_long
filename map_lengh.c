/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lengh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:39:38 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 11:40:07 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_coordinates	map_lengh_high(char **map)
{
	t_coordinates	size;

	size.y = 0;
	while (map[size.y] != NULL)
	{
		size.x = 0;
		while (map[size.y][size.x] != '\0')
			size.x++;
		size.y++;
	}
	return (size);
}
