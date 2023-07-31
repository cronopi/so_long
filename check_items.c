# include "ft_so_long.h"

void	check_items(char **tokens)
{
	int		i;
	int		j;
	char	P;
	char	E;
	char	C;

	P = 0;
	E = 0;
	C = 0;
	i = 0;
	j = 0;
	while(tokens[i] != NULL)
	{
		while (tokens[i][j] != '\0')
		{
			if (tokens[i][j] == 'P')
				P++;
			else if (tokens[i][j] == 'E')
				E++;
			else if (tokens[i][j] == 'C')
				C++;
			j++;
		}
		i++;
		j = 0;
	}
	if (E != 1)
	{
		perror("Error: map");
		exit(1);
	}
	else if (P != 1)
	{
		perror("Error: map");
		exit(1);
	}
	else if (C < 1)
	{
		perror("Error: map");
		exit(1);
	}
}
