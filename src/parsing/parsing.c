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

int	check_duplicate(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;

	i = *a;
	while (i)
	{
		j = (*i).next;
		while (j)
		{
			if (i->number == j->number)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	check_max(char **array, int size, t_stack **a)
{
	long	num;
	int		i;

	i = 0;
	while (i < size)
	{
		if (num_counting(array[i]))
			return (ft_printf("Error\nInt overflow.\n"),
				free_array(array, size), free_list(*a), 0);
		num = ft_atol(array[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_printf("Error\nInt overflow.\n"),
				free_array(array, size), free_list(*a), 0);
		list_init(a, (int)num);
		i++;
	}
	if (check_duplicate(a))
		return (ft_printf("Error\nRepeated numbers.\n"),
			free_array(array, size), free_list(*a), 0);
	free_array(array, size);
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
			{
				free_array(av, n);
				return (ft_printf("Error\nInvalid characters.\n"), 0);
			}
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
		if (ft_isdigit(av[1][i]))
			n++;
		if (!ft_isdigit(av[1][i]) && av[1][i] != ' ')
			return (ft_printf("Error\nInvalid characters.\n"), 0);
		while (av[1][i] != ' ' && av[1][i])
			i++;
	}
	return (n);
}

int	parsing(int ac, char **av, t_stack **a)
{
	char	**array;
	int		n;

	n = 0;
	array = NULL;
	if (ac == 2 && av[1][0])
	{
		n = check_arg(av);
		if (n > 0)
			array = ft_split(av[1], ' ');
		return (check_numbers(n, array, a));
	}
	if (ac > 2)
	{
		array = copy_argv(ac, av, array);
		return (check_numbers(ac - 1, array, a));
	}
	return (0);
}
