/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:56:20 by mefische          #+#    #+#             */
/*   Updated: 2025/08/08 16:29:07 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(int n, char **av)
{
	int	i;
	int	j;
	//t_stack	*a;
	
	i = 0;
	while (i < n) //vejo se sao numeros
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] <= '0' && av[i][j] >= '9')
				return (1);
			j++;
		}
		i++;
	}
	//criar um node para cada av[i] e colocar o numero la dentro
	return (0);
}

int	check_arg(char **av) //check se so numeros, INT_MINMAX, DUPLICADOS, EM ORDEM
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] != ' ') && (av[1][i] <= '0' && av[1][i] >= '9'))
			return (1);
		i++;
	}
	//funcao pra alocar estes em lista
	//comparacao entre numeros para ver se ha duplicados
	//comparacao para ver se estao na lista
	return (0);
}

int	parsing(int ac, char **av)
{
	if (ac == 1)
		return (1);
	if (ac == 2 && check_arg(av))//pode ser entre ""
		return (1);//dar free se alocar algo
	if (ac > 2 && check_numbers(ac, av))//so espacos
		return (1);//dar free se alocar algo
	return (0);
}