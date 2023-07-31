# include "ft_so_long.h"

t_coordinates	map_lengh_high(char **map)
{
	t_coordinates size;

	size.y = 0;
	while(map[size.y] != NULL)
	{
		size.x = 0;
		while (map[size.y][size.x] != '\0')
			size.x++;
		size.y++;
	}
	return (size);
}
