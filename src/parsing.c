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

int	check_numbers(int n, char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < n)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arg(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] != ' ') && (av[1][i] < '0' || av[1][i] > '9'))
			return (1);
		if (av[1][i] >= '0' && av[1][i] <= '9')
		{
			i++;
			if (av[1][i] != '\0')
				return (0);
			if (av[1][i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}
//atol: passar para int e check MIN/MAX
//alocar numeros em lista
//comparar nodes e ver se ha numeros iguais

int	parsing(int ac, char **av)
{
	if (ac == 1)
		return (1);
	if (ac == 2 && check_arg(av))
		return (ft_printf("Invalid args!\n"), 1);//dar free se alocar algo
	if (ac > 2 && check_numbers(ac, av))
		return (ft_printf("Invalid args!\n"), 1);//dar free se alocar algo
	if (ac == 2)
		list_init(av, 2);
	if (ac > 2)
		list_init(av, 1);
	return (0);
}
