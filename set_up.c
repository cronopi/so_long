# include "ft_so_long.h"

void	set_up(t_vars	vars, t_patata *patata)
{
	patata->img.steps = 0;
	patata->img.colectables_count = count_colectables(patata->img.map, patata);
	patata->img.exit = exit_position(patata->img.map);
	patata->img.player = player_position(patata->img.map);
	patata->img.exit.x = (patata->img.exit.x * 32) + 32;
	patata->img.exit.y = (patata->img.exit.y * 32) + 32;
	patata->img.player.x = (patata->img.player.x * 32) + 32;
	patata->img.player.y = (patata->img.player.y * 32) + 32;
	patata->mlx = vars.mlx;
	patata->win = vars.win;
	patata->img.exit_portal =  mlx_xpm_file_to_image(patata->mlx, "portal.xpm",  &(patata->a.x), &(patata->a.y));
	patata->img.wall =  mlx_xpm_file_to_image(patata->mlx, "wall.xpm", &patata->img.wall_size.x, &patata->img.wall_size.y);
	patata->img.colectables =  mlx_xpm_file_to_image(patata->mlx, "pacdot_food.xpm", &patata->img.colectables_size.x, &patata->img.colectables_size.y);
	patata->img.pacman = mlx_xpm_file_to_image(patata->mlx, "pac_open_right.xpm", &(patata->a.x), &(patata->a.y));
}