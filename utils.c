/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsoghom <arsoghom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:13:37 by arsoghom          #+#    #+#             */
/*   Updated: 2026/10/25 15:30:44 by arsoghom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_split(char *str)
{
	int		i;
	char	*res;

	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '9'))
			return (NULL);
		if (i % 2 == 1 && str[i] != ' ')
			return (NULL);
		res[i / 2] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
