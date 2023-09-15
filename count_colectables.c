/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_colectables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:51:50 by rcastano          #+#    #+#             */
/*   Updated: 2023/09/15 08:45:32 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	count_colectables(t_patata *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->img.colectables_count = 0;
	while (data->img.map[i] != NULL)
	{
		while (data->img.map[i][j] != '\0')
		{
			if (data->img.map[i][j] == 'C')
				data->img.colectables_count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (data->img.colectables_count);
}
