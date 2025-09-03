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

int	check_duplicate(int *numbers, int size)
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

int	check_max(char **array, int size, t_stack **a) 
{
	int		i;
	int		*numbers;
	long	num;

	i = 0;
	num = 0;
	numbers = malloc(sizeof (int) * size);
	while (i < size)
	{
		num = ft_atol(array[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_printf("Error\nInt overflow.\n"),
				free(numbers), free_list(*a), 0);
		list_init(a, (int)num);
		numbers[i] = (int)num;
		i++;
	}
	if (check_duplicate(numbers, size))
		return (ft_printf("Error\nRepeated numbers.\n"),
			free(numbers), free_array(array, size), free_list(*a), 0);
	free(numbers);
	return (size);
}

int	check_numbers(int n, char **av, t_stack **a)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (av[i][j])
		{
			if (((av[i][j] == '-') || (av[i][j] == '+'))
				&& ft_isdigit(av[i][j + 1]))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (ft_printf("Error\nInvalid characters.\n"), 0);
			j++;
		}
		i++;
	}
	return (check_max(av, n, a));
}

int	check_arg(char **av)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (av[1][i])
	{
		while (av[1][i] == ' ')
			i++;
		if (((av[1][i] == '-') || (av[1][i] == '+')) && ft_isdigit(av[1][i + 1]))
			i++;
		if (ft_isdigit(av[1][i]))
			n++;
		while (ft_isdigit(av[1][i]))
				i++;
		if ((av[1][i] < '0' || av[1][i] > '9') && (av[1][i] != ' ') && av[1][i])
			return (ft_printf("Error\nInvalid characters.\n"), 0);
	}
	return (n);
}

int	parsing(int ac, char **av, t_stack **a)
{
	char	**array;
	int		n;

	n = 0;
	if (ac == 2 && av[1][0])
	{
		n = check_arg(av);
		array = ft_split(av[1], ' ');
		return (check_numbers(n, array, a));
	}
	if (ac > 2)
	{
		array = av + 1;
		return (check_numbers(ac - 1, array, a));
	}
	return (0);
}
