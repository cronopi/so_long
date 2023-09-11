/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:36:07 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/05 13:50:50 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	items_errors(int e, int p, int c)
{
	if (e != 1 || p != 1 || c < 1)
	{
		ft_putstr_fd("Error\n", 1);
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
			j++;
		}
	else
		items_errors(e, p, c);
}

void	check_items(char **tokens)
{
	int		i;
	int		j;
/* 	char	p;
	char	e;
	char	c;

	p = 0;
	e = 0;
	c = 0; */
	i = 0;
	j = 0;
	while (tokens[i] != NULL)
	{
/*		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'P')
				p++;
			else if (tokens[i][j] == 'E')
				e++;
			else if (tokens[i][j] == 'C')
				c++;
			j++;
		} */
		PEC_count(tokens, j, i);
		i++;
		j = 0;
	}
	//items_errors(e, p, c);
}
