/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:56:20 by mefische          #+#    #+#             */
/*   Updated: 2025/08/11 10:04:05 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicate(long *numbers, int size)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_max(char **array, int size, long **numbers)
{
	int	i;

	i = 0;
	*numbers = malloc (sizeof(long) * size);
	while (i < size)
	{
		(*numbers)[i] = atol(array[i]);
		if ((*numbers)[i] > INT_MAX || (*numbers)[i] < INT_MIN)
			return (ft_printf("Error\nInt overflow.\n"),  free(*numbers), 0);
		i++;
	}
	if (check_duplicate(*numbers, size))
		return (ft_printf("Error\nRepeated numbers."), free(*numbers), 0);
	return (size);
}

int	check_numbers(int n, char **av, long **numbers)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < n)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-') && (av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (check_max(av + 1, n - 1, numbers)); //need to start in av[1]
}

int	check_arg(char **av, long **numbers)
{
	int	i;
	int	n;
	char **array;

	i = 0;
	n = 0;
	while (av[1][i])
	{
		while (av[1][i] == ' ')
			i++;
		if ((av[1][i] == '-') || (av[1][i] >= '0' && av[1][i] <= '9'))
		{
			n++;
			i++;
			while ((av[1][i] >= '0' && av[1][i] <= '9') && (av[1][i] != ' '))
				i++;
		}
		else if ((av[1][i] < '0' || av[1][i] > '9') && (av[1][i] != ' ') && av[1][i])
			return (0);
	}
	array = ft_split(av[1], ' ');
	if (!check_max(array, n, numbers))
		return (0);
	free_array(array, n);
	return (n);
}

int	parsing(int ac, char **av, long **numbers)
{
	if (ac <= 1)
		return (0);
	if (ac == 2)
		return (check_arg(av, numbers));
	if (ac > 2)
		return (check_numbers(ac, av, numbers));
	return (0);
}
