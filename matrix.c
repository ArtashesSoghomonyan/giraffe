/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsoghom <arsoghom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:20:37 by arsoghom          #+#    #+#             */
/*   Updated: 2026/10/25 15:11:17 by arsoghom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_sqrt(int num);

char	**create_matrix(int size)
{
	char	**res;
	int		i;
	int		j;

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

void	free_matrix(char **matrix, int size)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**args_to_walls(char *str, int s)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(4 * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		res[i] = malloc(s * sizeof(char));
		if (!res[i])
		{
			free_matrix(res, i);
			return (NULL);
		}
		j = 0;
		while (j < s)
		{
			res[i][j] = str[i * s + j];
			j++;
		}
		i++;
	}
	return (res);
}
