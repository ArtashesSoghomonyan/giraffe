/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsoghom <arsoghom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:30:11 by arsoghom          #+#    #+#             */
/*   Updated: 2026/10/25 15:45:08 by arsoghom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_sqrt(int num);
void	print_error(char *str);
int		ft_strlen(char *str);

int	check_args(char *str)
{
	int	i;
	int	s;
	int	l;

	l = ft_strlen(str);
	if (l % 4 != 0){
		print_error("Arguments count error\n");
		return (0);
	}
	s = l / 4;
	if (s < 4 || s > 9){
		print_error("Invalid count\n");
		return (0);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] < '1' || str[i] > s + '0')
			return (print_error("Invalid arguments\n"), 0);
		i++;
	}
	return (s);
}

int	valid(char **matrix, int size, int pos, char num)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = pos / size;
	col = pos % size;
	while (i < size)
	{
		if (matrix[row][i] == num || matrix[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	get_height(char **m, int s, int pos, int i)
{
	int	index;
	int	dir;

	dir = pos / s;
	index = pos % s;
	if (dir == 0)
		return (m[i][index] - '0');
	if (dir == 1)
		return (m[s - 1 - i][index] - '0');
	if (dir == 2)
		return (m[index][i] - '0');
	return (m[index][s - 1 - i] - '0');
}

int	check_wall(char **m, int s, int index, int dir)
{
	int	i;
	int	max;
	int	count;
	int	height;

	i = 0;
	max = 0;
	count = 0;
	while (i < s)
	{
		height = get_height(m, s, dir * s + index, i);
		if (height > max)
		{
			max = height;
			count++;
		}
		i++;
	}
	return (count);
}

int	check_all(char **matrix, int size, char **walls)
{
	int	i;
	int	dir;

	dir = 0;
	while (dir < 4)
	{
		i = 0;
		while (i < size)
		{
			if (check_wall(matrix, size, i, dir)
				!= walls[dir][i] - '0')
			{
				return (0);
			}
			i++;
		}
		dir++;
	}
	return (1);
}

int	fill(char **matrix, int size, char **walls, int pos)
{
	int		r;
	int		c;
	char	n;

	if (pos == size * size)
		return (check_all(matrix, size, walls));
	r = pos / size;
	c = pos % size;
	n = '1';
	while (n <= size + '0')
	{
		if (valid(matrix, size, pos, n))
		{
			matrix[r][c] = n;
			if (fill(matrix, size, walls, pos + 1))
			{
				return (1);
			}
			matrix[r][c] = '-';
		}
		n++;
	}
	return (0);
}
