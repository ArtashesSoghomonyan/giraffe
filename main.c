/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsoghom <arsoghom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 15:40:12 by arsoghom          #+#    #+#             */
/*   Updated: 2026/10/24 17:04:15 by arsoghom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**create_matrix(int size)
{
	char	**res;
	int	i;
	int	j;

	res = malloc(size * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = malloc(size * sizeof(char));
		if (!res[i])
			return (NULL);
		j = 0;
		while (j < size)
		{
			res[i][j] = '-';
			j++;
		}
		i++;
	}
	return (res);
}

void	print_matrix(char **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &matrix[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_sqrt(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i <= num / 2)
	{
		if (i * i == num)
			return (i);
		i++;
	}
	return (0);
}

void	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**args_to_walls(int argc, char *argv[])
{
	char	**res;
	int	i;
	int	j;
	int	c;
	res = malloc(4 * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	c = 1;
	while (i < 4)
	{
		res[i] = malloc(ft_sqrt(argc - 1) * sizeof(char));
		if (!res[i])
			return (NULL);
		j = 0;
		while (j < ft_sqrt(argc - 1))
		{
			res[i][j] = argv[c][0];
			write(1, &res[i][j], 1); //
			c++;
			j++;
		}
		write(1, "\n", 1); //
		i++;
	}

	return (res);
}

int	check_args(int argc, char *argv[])
{
	int	i;
	int	s;

	s = ft_sqrt(argc - 1);
	if (s == 0)
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

void	fill(char **matrix, int size, char **walls)
{
	int	i;
	int	j;
	int	n;
	
	i = 0;
	while (i < 4)
	{
		if (i == 0)
		{
			j = 0;
			while (j < size)
			{
				if (walls[i][j] == '1'){
					n = 0;
					while(n <= size){
						matrix[n][j] = n + 1 + '0';
						n++;
					}
			}
			j++;	
			}
		}
		if (i == 1)
		{}
		if (i == 2)
		{}
		if (i == 3)
		{}
		i++;
	}
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (check_args(argc, argv) == -1)
		return (1);
	int size = ft_sqrt(argc - 1);
	char **matrix = create_matrix(size);
	char **walls = args_to_walls(argc, argv);
	fill(matrix, size, walls);
	print_matrix(matrix, size);
	return (0);
}
