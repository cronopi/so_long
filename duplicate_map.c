/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:00:59 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 08:39:42 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	**duplicate_map(t_patata *init)
{
	int		y;
	int		x;
	char	**duplicate;

	x = 0;
	y = 0;
	while (init->img.map[y] != NULL)
	{
		while (init->img.map[y][x] != '\0')
			x++;
		y++;
		x = 0;
	}
	duplicate = malloc(sizeof(char *) * (y + 1));
	if (!duplicate)
		return (0);
	duplicate[y] = NULL;
	while (y != 0)
	{
		y--;
		duplicate[y] = ft_strdup(init->img.map[y]);
	}
	return (duplicate);
}
