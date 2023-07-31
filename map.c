# include "ft_so_long.h"

char	**open_map(int argc, char **argv)
{
	int	fd;
	char **tokens;
	int	i;
	int j;
	int check;

	tokens = NULL;
	i = 0;
	j = 0;
	check = 0;
	if (argc != 2)
	{
		perror("Error: map");
		exit(1);
	}
	if (argv[1]) // que tenga nombre .ber y nada más despues
	{
		while(argv[1][i] != '\0')
		{
			if (argv[1][i] == '.')
				if (strcmp(&argv[1][i], ".ber") == 0)
				{
					printf("estas bien\n");
					check = 1;
				}
			i++;
		}
		if (argv[1][i] != '\0' && check == 0)
		{
			printf("test2\n");
			perror("Error: map");
		}
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("file not found");
		exit(1);
	}
	while(get_next_line(fd))
		i++;
	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (j <= i)
	{
		tokens[j] = get_next_line(fd);
		j++;
	}
	i = 0;
	j = 0;
	while(tokens[i][j])
		j++;
	check_map(tokens);
	map_lengh_high(tokens);
	j = 0;
	close(fd);
	return (tokens);
}
