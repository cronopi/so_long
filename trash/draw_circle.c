/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:32:15 by roberto           #+#    #+#             */
/*   Updated: 2023/06/23 17:50:01 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	//mlx_pixel_put(data->mlx, data->win, x, y, color);
}

int	draw_circle(void *patata)
{
	int	lengh;
	int	x;
	int	y;
	t_patata *test;

	test = patata;
	lengh = 25;
	x = 0;
	y = 0;
	mlx_clear_window(test->mlx, test->win);
	while(y < lengh)
	{
		my_mlx_pixel_put(&(test->img), test->a.x + x, test->a.y + y, 0x00FF0000);
		x++;
		if (x == lengh)
		{
			x = 0;
			y++;
		}
	}
	mlx_put_image_to_window(test->mlx, test->win, test->img.img, 0, 0);
	return 1;
}
