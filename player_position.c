# include "ft_so_long.h"

t_coordinates	player_position(char **tokens)
{
	t_coordinates	player;

	player.x = 0;
	player.y = 0;
	while(tokens[player.y][player.x])
	{
		while (tokens[player.y][player.x] != '\0')
		{
			if (tokens[player.y][player.x] == 'P')
				return (player);
			player.x++;
		}
		player.y++;
		player.x = 0;
	}
	return (player);
}
