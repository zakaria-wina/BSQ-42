#include "../includes/head.h"

extern	int	lines;
extern	char	empty;

char	**ft_read_map(int fd, int n_char_in_line)
{
	char	**map;
	char	char_readed;
	int		i;

	map = (char **)malloc(sizeof (char *) * lines);
	if (!map) return (0);
	i = -1;
	while (++i < lines)
	{
		map[i] = (char *)malloc(sizeof (char) * (n_char_in_line + 1));
		if (!(map[i])) return (0);
	}
	do read(fd, &char_readed, 1); while (char_readed != '\n');
	i = 0;
	while (i < lines) read(fd, map[i++], n_char_in_line + 1);
	close(fd);
	return (map);
}

void	ft_change_square(t_square *biggest_square, int i, int j, int k)
{
	biggest_square->x = i;
	biggest_square->y = j;
	biggest_square->len = k;
}

int	ft_valid_square(char **map, int i, int j, int k)
{
	int	l;

	l = 0;
	while (l < k)
	{
		if (map[i + k - 1][j + l] != empty || map[i + l][j + k - 1] != empty) return (0);
		l++;
	}
	return (1);
}

void	ft_find_square(t_square *biggest_square, char **map, int n_char_in_line)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < n_char_in_line)
		{
			k = 1;
			while (k + i <= lines && k + j <= n_char_in_line)
			{
				if (ft_valid_square(map, i, j, k))
				{
					if (biggest_square->len < k)
						ft_change_square(biggest_square, i, j, k);
					k++;
				}
				else break;
			}
			j++;
		}
		i++;
	}
}
