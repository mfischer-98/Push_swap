/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:44:41 by mefische          #+#    #+#             */
/*   Updated: 2025/08/20 17:44:41 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	t_stack	*temp;
	int		max;
	int		i;
	int		j;

	i = -1;
	index_list(a);
	max = max_bits(size - 1);
	while (++i < max)
	{
		j = 0;
		while (j < size)
		{
			temp = *a;
			if (((temp->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
	}
}

int	max_bits(int size)
{
	int		max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
