#include "../includes/head.h"

extern	int	lines;

int	main(int ac, char **av)
{
	t_square biggest_square;
	int	i;
	int	fd;
	int	n_char_in_line;
	char	**map;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		n_char_in_line = ft_valid_map(fd);
		if (n_char_in_line)
		{
			fd = open(av[i], O_RDONLY);
			map = ft_read_map(fd, n_char_in_line);
			biggest_square.len = 0;
			ft_find_square(&biggest_square, map, n_char_in_line);
			ft_solution(biggest_square, map, n_char_in_line);
		}
		else write(1, "map error\n", 10);
		i++;
	}
	return (0);
}
