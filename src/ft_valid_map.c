#include "../includes/head.h"

char			empty;
char			obs;
char			full;
int				lines;

int	ft_number_of_lines(int fd)
{
	char	char_readed;

	char_readed = 0;
	while (read(fd, &char_readed, 1))
	{
		if (char_readed >= '0' && char_readed <= '9') lines = lines * 10 + char_readed - '0';
		else
		{
			empty = char_readed;
			break;
		}
	}
	if (lines > 0) return (1);
	return (0);
}

int	ft_read_lines(int fd)
{
	char	char_readed;
	int		char_in_line;

	char_in_line = 0;
	do
	{
		if (read(fd, &char_readed, 1) == 0) return (0);
		if (char_readed != empty && char_readed != obs && char_readed != '\n') return (0);
		if (char_readed != '\n') char_in_line++;
	} while (char_readed != '\n');
	return (char_in_line);
}

int	ft_valid_map(int fd)
{
	char			char_readed;
	int				i;
	int				n_char_in_line;
	int				pn_char_in_line;

	if (ft_number_of_lines(fd) == 0) return (0);
	read(fd, &obs, 1);
	read(fd, &full, 1);
	read(fd, &char_readed, 1);
	if (char_readed != '\n') return (0);
	i = 0;
	pn_char_in_line = 0;
	while (i < lines)
	{
		n_char_in_line = ft_read_lines(fd);
		if (!n_char_in_line) return (0);
		if (pn_char_in_line != n_char_in_line && pn_char_in_line) return (0);
		pn_char_in_line = n_char_in_line;
		i++;
	}
	return (n_char_in_line);
}
