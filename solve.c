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

int	check_args(int argc, char *argv[])
{
	int	i;
	int	s;

	if (argc != 2)
	{
		print_error("Argument count error\n");
		return (-1);
	}
	
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != 1 || argv[i][0] < '0' || argv[i][0] > '9'
			|| !(argv[i][0] - '0' >= 1 && argv[i][0] - '0' <= s))
		{
			print_error("Wrong arguments error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	valid(char **matrix, int size, int pos, char num)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = pos / 4;
	col = pos % 4;
	while (i < size)
	{
		if (matrix[row][i] == num || matrix[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **matrix, int size, int index, int dir)
{
	int	i;
	int	max;
	int	count;
	int	height;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (dir < 2)
			height = matrix[dir * (size - 3 * i)
				+ i][index] - '0';
		else
			height = matrix[index][(dir - 2) * (size - 3 * i)
				+ i] - '0';
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
