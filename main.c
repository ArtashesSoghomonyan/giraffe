
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsoghom <arsoghom@student.42.fr>          +#+  +:+       +#+        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	print_error(char *str);
char	*ft_split(char *str);
int		check_args(char *str);
char	**create_matrix(int s);
char	**args_to_walls(char *str, int s);
int		fill(char **matrix, int s, char **walls, int pos);
void	print_matrix(char **matrix, int s);
void	free_matrix(char **matrix, int s);

int	check_input(int argc, char **argv, char **input)
{
	int	s;

	if (argc != 2)
	{
		print_error("Error\n");
		return (0);
	}
	*input = ft_split(argv[1]);
	if (!*input)
	{
		print_error("Error\n");
		return (0);
	}
	s = check_args(*input);
	if (s == 0)
	{
		free(*input);
		return (0);
	}
	return (s);
}

int	run(char *input, int s)
{
	char	**matrix;
	char	**walls;
	int		found;

	matrix = create_matrix(s);
	if (!matrix)
		return (print_error("Error\n"), 0);
	walls = args_to_walls(input, s);
	if (!walls)
	{
		free_matrix(matrix, s);
		return (print_error("Error\n"), 0);
	}
	found = fill(matrix, s, walls, 0);
	if (found)
		print_matrix(matrix, s);
	else
		print_error("Error\n");
	free_matrix(walls, 4);
	free_matrix(matrix, s);
	return (found);
}

int	main(int argc, char **argv)
{
	char	*input;
	int		s;
	int		found;

	s = check_input(argc, argv, &input);
	if (s == 0)
		return (1);
	found = run(input, s);
	free(input);
	if (!found)
		return (1);
	return (0);
}

