/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:36:07 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/12 13:22:54 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	items_errors(int e, int p, int c, char **tokens)
{
	if (e != 1 || p != 1 || c < 1)
	{
		ft_putstr_fd("Error\n", 1);
		free_map(tokens);
		//mlx_destroy_display(init->mlx);// solo funciona en linux
		//free(init->mlx);
		exit(1);
	}
}

void	PEC_count(char **tokens, int j, int i)
{
	char	p;
	char	e;
	char	c;

	p = 0;
	e = 0;
	c = 0;
	if (tokens[i][j] != '\0')
		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'P')
				p++;
			else if (tokens[i][j] == 'E')
				e++;
			else if (tokens[i][j] == 'C')
				c++;
			else if (tokens[i][j] != '1' && tokens[i][j] != '0')
				items_errors(e, 0, c, tokens);// exit con liberacion
			j++;
		}
	else
		items_errors(e, p, c, tokens);
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
	while (tokens[i] != NULL)
	{
		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'P')
				p++;
			else if (tokens[i][j] == 'E')
				e++;
			else if (tokens[i][j] == 'C')
				c++;
			else if (tokens[i][j] != '1' && tokens[i][j] != '0' && tokens[i][j] != '\r' && tokens[i][j] != '\n')
			{
				ft_putstr_fd("Entras o no?\n", 1);
				items_errors(e, 0, c, tokens);// exit con liberacion
			}
			j++;
		}
		//PEC_count(tokens, j, i);
		i++;
		j = 0;
	}
	items_errors(e, p, c, tokens);
}
