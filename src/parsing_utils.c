/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:52:01 by mefische          #+#    #+#             */
/*   Updated: 2025/08/13 10:52:01 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(long *num, int n)
{
	int	i;

	i = 0;
	while(i < n - 1)
	{
		if (num[i] > num[i + 1])
			return (ft_printf("Numbers not sorted :)\n"), 0);
		i++;
	}
	return (ft_printf("Numbers sorted :("), 1);
}

void	free_array(char **array, int n)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < n)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
