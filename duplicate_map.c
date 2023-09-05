/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:00:59 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/05 10:29:53 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	**duplicate_map(char **tokens)
{
	int		y;
	int		x;
	char	**duplicate;

	x = 0;
	y = 0;
	while (tokens[y] != NULL)
	{
		while (tokens[y][x] != '\0')
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
		duplicate[y] = ft_strdup(tokens[y]);
	}
	return (duplicate);
}
