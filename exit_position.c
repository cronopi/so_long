# include "ft_so_long.h"

t_coordinates	exit_position(char **tokens)
{
	t_coordinates	exit;

	exit.x = 0;
	exit.y = 0;
	while(tokens[exit.y][exit.x])
	{
		while (tokens[exit.y][exit.x] != '\0')
		{
			if (tokens[exit.y][exit.x] == 'E')
				return (exit);
			exit.x++;
		}
		exit.y++;
		exit.x = 0;
	}
	return (exit);
}
