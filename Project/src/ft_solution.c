#include "../includes/head.h"

extern	int	lines;
extern	int	full;

int	ft_valid_range(int i, int from, int to)
{
	if (i >= from && i < from + to)
		return (1);
	return (0);
}

void	ft_solution(t_square biggest_square, char **map, int n_char_in_line)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < n_char_in_line)
		{
			if (ft_valid_range(i, biggest_square.x, biggest_square.len) &&
				ft_valid_range(j, biggest_square.y, biggest_square.len))
				write(1, &full, 1);
			else write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
