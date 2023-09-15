/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:36:07 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 10:49:41 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	items_errors(int e, int p, int c, t_patata *init)
{
	if (e != 1 || p != 1 || c < 1)
	{
		ft_putstr_fd("Error\n", 1);
		free_map(init->img.duplicate_map);
		//mlx_destroy_display(init->mlx);// solo funciona en linux
		//free(init->mlx);
		exit(1);
	}
}

/* void	PEC_count(t_patata *init)
{
	char	p;
	char	e;
	char	c;

	p = 0;
	e = 0;
	c = 0;

} */

void	check_items(t_patata *init)
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
	while (init->img.duplicate_map[i] != NULL)
	{
		while (init->img.duplicate_map[i][j] != '\0')
		{
			if (init->img.duplicate_map[i][j] == 'P')
				p++;
			else if (init->img.duplicate_map[i][j] == 'E')
				e++;
			else if (init->img.duplicate_map[i][j] == 'C')
				c++;
			else if (init->img.duplicate_map[i][j] != '1' && init->img.duplicate_map[i][j] != '0' && init->img.duplicate_map[i][j] != '\r' && init->img.duplicate_map[i][j] != '\n')
			{
				ft_putstr_fd("Entras o no?\n", 1);
				items_errors(e, 0, c, init);// exit con liberacion
			}
			j++;
		}
		//PEC_count(init->img.duplicate_map, j, i);
		i++;
		j = 0;
	}
	items_errors(e, p, c, init);
}
