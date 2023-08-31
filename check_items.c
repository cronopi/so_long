/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:36:07 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 10:26:22 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	items_errors(int e, int p, int c)
{
	if (e != 1 || p != 1 || c < 1)
	{
		perror("Error: map");
		exit(1);
	}
}

void	check_items(char **tokens)
{
	int		i;
	int		j;
	char	p;
	char	e;
	char	c;

	p = 0;
	e = 0;
	c = 0;
	i = 0;
	j = 0;
	while (tokens[i++] != NULL)
	{
		while (tokens[i][j++] != '\0')
		{
			if (tokens[i][j] == 'P')
				p++;
			else if (tokens[i][j] == 'E')
				e++;
			else if (tokens[i][j] == 'C')
				c++;
			//j++;
		}
		//i++;
		j = 0;
	}
	items_errors(e, p, c);
}

/*	if (E != 1 || P != 1 || C < 1)
	{
		perror("Error: map");
		exit(1);
	} */