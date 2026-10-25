/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsoghom <arsoghom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 15:40:12 by arsoghom          #+#    #+#             */
/*   Updated: 2026/10/25 15:31:47 by arsoghom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils.c
int		ft_sqrt(int num);

// matrix.c
char	**create_matrix(int size);
void	print_matrix(char **matrix, int size);
void	free_matrix(char **matrix, int size);
char	**args_to_walls(int argc, char *argv[]);

// solve.c
int		check_args(int argc, char *argv[]);
int		fill(char **matrix, int size, char **walls, int pos);

int	main(int argc, char *argv[])
{
	int		size;
	char	**matrix;
	char	**walls;

	if (check_args(argc, argv) == -1)
		return (1);
	size = ft_sqrt(argc - 1);
	matrix = create_matrix(size);
	walls = args_to_walls(argc, argv);
	fill(matrix, size, walls);
	print_matrix(matrix, size);
	free_matrix(matrix, size);
	return (0);
}
