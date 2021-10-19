#ifndef HEAD_H
# define HEAD_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include<stdio.h>

typedef	struct	s_square
{
	int		x;
	int		y;
	int		len;
}				t_square;

int		ft_number_of_lines(int);
int		ft_read_lines(int);
int		ft_valid_map(int);
char	**ft_read_map(int, int);
void	ft_find_square(t_square *, char **, int);
void	ft_solution(t_square, char **, int);

#endif
