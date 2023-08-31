/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_colectables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:51:50 by rcastano          #+#    #+#             */
/*   Updated: 2023/08/31 10:51:51 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	count_colectables(char **tokens, t_patata *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->img.colectables_count = 0;
	while (tokens[i] != NULL)
	{
		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'C')
				data->img.colectables_count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (data->img.colectables_count);
}
