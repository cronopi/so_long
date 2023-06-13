/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:40:55 by rcastano          #+#    #+#             */
/*   Updated: 2023/06/13 10:55:48 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "so_long.h"
# include "mlx.h"

int main(void)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "patata");

	mlx_loop(mlx);
	return (0);
}